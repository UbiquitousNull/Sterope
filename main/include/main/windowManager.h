#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <stddef.h>

#include "main.h"

typedef struct WindowManager{
    WINDOW* arr;
    size_t  len;
    size_t  cap;
} WindowManager;

#endif // WINDOWMANAGER_H