#ifndef EVENTSYS_H
#define EVENTSYS_H

/*
 *
 *  Header file for eventSys.c
 * 
 *  This file contains the definitions and function prototypes for the event system.
 *
 */

#include "multithreading.h"

typedef struct {
	int eventId;
	struct handlers {
		void (**handlers)(void*);
		size_t count;
		size_t maxCount;
	} handlers;
	rwlock_t event_rwlock;
} Event;

typedef struct {
	Event** events;
	size_t size;
	size_t capacity;
	rwlock_t registry_rwlock;
} EventRegistry;

EventRegistry* createRegistry(size_t initialCapacity);
Event* createEvent(EventRegistry* registry, int eventId, size_t initialCapacity);
void registerHandler(Event* event, void (*handler)(void*));
void triggerEvent(Event* event, void* data);
void freeRegistry(EventRegistry* registry);
void freeEvent(Event* event);

#endif // EVENTSYS_H