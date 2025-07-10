#ifndef UTILS_H
#define UTILS_H

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define RETURN_ERR(...) { fprintf(stderr, __VA_ARGS__); exit(); } // Might become deprecated, use MSGBOX_ERR instead
#define MSGBOX_ERR(fmt, ...) do { \
    int needed = snprintf(NULL, 0, "%s:%d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
    if (needed > 0) { \
        char* buf = (char*)malloc(needed + 1); \
        if (buf) { \
            snprintf(buf, needed + 1, "%s:%d: " fmt, __FILE__, __LINE__, ##__VA_ARGS__); \
            MessageBoxA(NULL, buf, "Error", MB_OK | MB_ICONERROR); \
            free(buf); \
        } \
    } \
	shutdownTotal(); \
} while (0)

#include "Logging.h"
#include "io.h"
#include "main.h"
#ifdef _WIN32
	#include <windows.h>
	#include <winuser.h>
#endif

#endif // UTILS_H