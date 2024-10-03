#include "eventSys.h"

void createEvent(Event* event) {
    if (event == NULL) {
        // fprintf(stderr, "Error: Event pointer is NULL.\n");
        return;
    }

    CallbackList* list = malloc(sizeof(CallbackList));
    if (list == NULL) {
        // fprintf(stderr, "Error: Failed to allocate memory for CallbackList.\n");
        return;
    }
    list->ref_count = 1;
    list->count = 0;
    list->callbacks = NULL;

    atomic_store(&event->callback_list, list);
}

int addCallback(Event* event, Callback cb) {
    if (event == NULL) {
        // fprintf(stderr, "Error: Event pointer is NULL.\n");
        return -1;
    }
    if (cb == NULL) {
        // fprintf(stderr, "Error: Callback function pointer is NULL.\n");
        return -1;
    }

    CallbackList* old_list = atomic_load(&event->callback_list);
    if (old_list == NULL) {
        // fprintf(stderr, "Error: Callback list is NULL.\n");
        return -1;
    }

    CallbackList* new_list = malloc(sizeof(CallbackList));
    if (new_list == NULL) {
        // fprintf(stderr, "Error: Failed to allocate memory for new CallbackList.\n");
        return -1;
    }
    new_list->count = old_list->count + 1;
    new_list->callbacks = malloc(new_list->count * sizeof(Callback));
    if (new_list->callbacks == NULL) {
        // fprintf(stderr, "Error: Failed to allocate memory for callbacks array.\n");
        free(new_list);
        return -1;
    }
    new_list->ref_count = 1;

    for (int i = 0; i < old_list->count; i++) {
        new_list->callbacks[i] = old_list->callbacks[i];
    }
    new_list->callbacks[old_list->count] = cb;

    atomic_store(&event->callback_list, new_list);

    if (atomic_fetch_sub(&old_list->ref_count, 1) == 1) {
        free(old_list->callbacks);
        free(old_list);
    }

    return 0;
}

int removeCallback(Event* event, Callback cb) {
    if (event == NULL) {
        // fprintf(stderr, "Error: Event pointer is NULL.\n");
        return -1;
    }
    if (cb == NULL) {
        // fprintf(stderr, "Error: Callback function pointer is NULL.\n");
        return -1;
    }

    CallbackList* old_list = atomic_load(&event->callback_list);
    if (old_list == NULL) {
        // fprintf(stderr, "Error: Callback list is NULL.\n");
        return -1;
    }

    atomic_fetch_add(&old_list->ref_count, 1);

    int index = -1;
    for (int i = 0; i < old_list->count; i++) {
        if (old_list->callbacks[i] == cb) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        // fprintf(stderr, "Error: Callback not found in the event's callback list.\n");
        if (atomic_fetch_sub(&old_list->ref_count, 1) == 1) {
            free(old_list->callbacks);
            free(old_list);
        }
        return -1;
    }

    int new_count = old_list->count - 1;
    CallbackList* new_list = malloc(sizeof(CallbackList));
    if (new_list == NULL) {
        // fprintf(stderr, "Error: Failed to allocate memory for new CallbackList.\n");
        if (atomic_fetch_sub(&old_list->ref_count, 1) == 1) {
            free(old_list->callbacks);
            free(old_list);
        }
        return -1;
    }

    new_list->count = new_count;
    new_list->callbacks = malloc(new_count * sizeof(Callback));
    if (new_list->callbacks == NULL) {
        // fprintf(stderr, "Error: Failed to allocate memory for callbacks array.\n");
        free(new_list);
        if (atomic_fetch_sub(&old_list->ref_count, 1) == 1) {
            free(old_list->callbacks);
            free(old_list);
        }
        return -1;
    }
    new_list->ref_count = 1;

    for (int i = 0, j = 0; i < old_list->count; i++) {
        if (i != index) {
            new_list->callbacks[j++] = old_list->callbacks[i];
        }
    }

    atomic_store(&event->callback_list, new_list);

    if (atomic_fetch_sub(&old_list->ref_count, 1) == 1) {
        free(old_list->callbacks);
        free(old_list);
    }

    return 0;
}

void triggerEvent(Event* event, void* data) {
    if (event == NULL) {
        // fprintf(stderr, "Error: Event pointer is NULL.\n");
        return;
    }

    CallbackList* list = atomic_load(&event->callback_list);
    if (list == NULL) {
        // fprintf(stderr, "Error: Callback list is NULL.\n");
        return;
    }

    atomic_fetch_add(&list->ref_count, 1);

    for (int i = 0; i < list->count; i++) {
        if (list->callbacks[i] != NULL) {
            list->callbacks[i](data);
        } else {
            // fprintf(stderr, "Warning: Callback at index %d is NULL.\n", i);
        }
    }

    if (atomic_fetch_sub(&list->ref_count, 1) == 1) {
        free(list->callbacks);
        free(list);
    }
}
