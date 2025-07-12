#ifndef UTILS_H
#define UTILS_H

#include "Logging.h"
#include "io.h"
#include "main.h"

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define RETURN_ERR(...) { fprintf(stderr, __VA_ARGS__); exit(); } // Might become deprecated, use MSGBOX_ERR instead

#ifdef _WIN32
	#include <windows.h>
	#include <winuser.h>

	// This macro currently does not have a unix equivalent, as it is used for Windows message boxes.
	// I plan to implement a similar function for Unix systems in the future. (relevant notes on line 31)
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
#elif if __unix__ || __APPLE__
	#define MSGBOX_ERR(fmt, ...) do { \
	/* implement a unix version of this macro later */ \
	shutdownTotal(); \
} while (0)
#endif

#endif // UTILS_H