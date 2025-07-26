#include <stdlib.h>
#include "multithreading.h"
#include "eventSys.h"

EventRegistry* createRegistry(size_t initialCapacity)
{
	EventRegistry* registry = malloc(sizeof(EventRegistry));
	registry->events = malloc(sizeof(Event*) * initialCapacity);
	registry->size = 0;
	registry->capacity = initialCapacity;
	rwlock_init(&registry->registry_rwlock);

	return registry;
}

Event* createEvent(EventRegistry* registry, int eventId, size_t initialCapacity)
{
	Event* event = malloc(sizeof(Event));
	event->eventId = eventId;
	event->handlers.handlers = malloc(sizeof(void (*)(void*)) * initialCapacity);
	event->handlers.count = 0;
	event->handlers.maxCount = initialCapacity;
	rwlock_init(&event->event_rwlock);

	rwlock_write_lock(&registry->registry_rwlock);
	if (registry->size >= registry->capacity) {
		registry->capacity *= 2;
		registry->events = realloc(registry->events, sizeof(Event*) * registry->capacity);
	}
	registry->events[registry->size++] = event;
	rwlock_write_unlock(&registry->registry_rwlock);

	return event;
}

void registerHandler(Event* event, void (*handler)(void*))
{
	rwlock_write_lock(&event->event_rwlock);
	if (event->handlers.count >= event->handlers.maxCount) {
		event->handlers.maxCount *= 2;
		event->handlers.handlers = realloc(event->handlers.handlers, sizeof(void (*)(void*)) * event->handlers.maxCount);
	}
	event->handlers.handlers[event->handlers.count++] = handler;
	rwlock_write_unlock(&event->event_rwlock);
}

void triggerEvent(Event* event, void* data)
{
	rwlock_read_lock(&event->event_rwlock);
	for (size_t i = 0; i < event->handlers.count; i++) {
		event->handlers.handlers[i](data);
	}
	rwlock_read_unlock(&event->event_rwlock);
}

void freeEvent(Event* event)
{
	rwlock_write_lock(&event->event_rwlock);
	free(event->handlers.handlers);
	rwlock_write_unlock(&event->event_rwlock);
	rwlock_destroy(&event->event_rwlock);
	free(event);
}

void freeRegistry(EventRegistry* registry)
{
	rwlock_write_lock(&registry->registry_rwlock);
    for (size_t i = 0; i < registry->size; i++) {
        freeEvent(registry->events[i]);
    }
    free(registry->events);
    rwlock_write_unlock(&registry->registry_rwlock);
    free(registry);
}
