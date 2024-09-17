#ifndef EVENTSYS_H
#define EVENTSYS_H

#ifdef _WIN32
    #include <windows.h>
	typedef SRWLOCK rwlock_t;
    #define rwlock_init(lock) InitializeSRWLock(lock)
    #define rwlock_read_lock(lock) AcquireSRWLockShared(lock)
    #define rwlock_read_unlock(lock) ReleaseSRWLockShared(lock)
    #define rwlock_write_lock(lock) AcquireSRWLockExclusive(lock)
    #define rwlock_write_unlock(lock) ReleaseSRWLockExclusive(lock)
#elif __unix__ || __APPLE__
    #include <pthread.h>
	typedef pthread_rwlock_t rwlock_t;
    #define rwlock_init(lock) pthread_rwlock_init(lock, NULL)
    #define rwlock_read_lock(lock) pthread_rwlock_rdlock(lock)
    #define rwlock_read_unlock(lock) pthread_rwlock_unlock(lock)
    #define rwlock_write_lock(lock) pthread_rwlock_wrlock(lock)
    #define rwlock_write_unlock(lock) pthread_rwlock_unlock(lock)
    #define rwlock_destroy(lock) pthread_rwlock_destroy(lock)
#else	
#error "eventSys.h | Unsupported platform: Ask UbiquitousNull for assistance and/or forgiveness."
#endif

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