#ifndef EVENTSYS_H
#define EVENTSYS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>

typedef void (*Callback)(void*);

typedef struct {
    atomic_int ref_count;
    int count;
    Callback* callbacks;
} CallbackList;

typedef struct {
    _Atomic(CallbackList*) callback_list;
} Event;

void createEvent(Event* event);
int addCallback(Event* event, Callback cb);
int removeCallback(Event* event, Callback cb);
void triggerEvent(Event* event, void* data);

#define ADD_CALLBACKS(event, ...) do {									\
    if ((event) == NULL) {												\
    	        														\ // fprintf(stderr, "Error: Event pointer is NULL.\n");
    } else {															\
        Callback callbacks[] = { __VA_ARGS__ };							\
        size_t num_callbacks = sizeof(callbacks) / sizeof(Callback);	\
        for (size_t i = 0; i < num_callbacks; ++i) {					\
            if (callbacks[i] != NULL) {									\
                addCallback(event, callbacks[i]);						\
            } else {													\
            															\ // fprintf(stderr, "Warning: Callback at index %zu is NULL.\n", i);
            }															\
        }																\
    }																	\
} while(0)


#endif // EVENTSYS_H
