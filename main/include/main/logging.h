#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_LOG_LENGTH 1024

// Macros
#define LOG_LEVEL_DEBUG "DEBUG"
#define LOG_LEVEL_INFO "INFO"
#define LOG_LEVEL_WARNING "WARNING"
#define LOG_LEVEL_ERROR "ERROR"
#define LOG(level, ...) writeLog(level, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_DEBUG(...) writeLog(LOG_LEVEL_DEBUG, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_INFO(...) writeLog(LOG_LEVEL_INFO, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_WARNING(...) writeLog(LOG_LEVEL_WARNING, __FILE__, __LINE__, __VA_ARGS__)
#define LOG_ERROR(...) writeLog(LOG_LEVEL_ERROR, __FILE__, __LINE__, __VA_ARGS__)

#if defined(__GNUC__) || defined(__clang__)
  #define ATTR_PRINTF(fmt_index, args_index) __attribute__((format(printf, fmt_index, args_index)))
#else
  #define ATTR_PRINTF(fmt_index, args_index)
#endif

// Function prototypes
int writeLog(const char* level, const char* file, int line, const char* fmt, ...) ATTR_PRINTF(4, 5);

#endif // LOGGING_H