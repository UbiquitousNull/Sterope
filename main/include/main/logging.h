#ifndef LOGGING_H
#define LOGGING_H

#include <stdio.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_LOG_LENGTH 1024

// Log levels
#define LOG_LEVEL_DEBUG "DEBUG"
#define LOG_LEVEL_INFO "INFO"
#define LOG_LEVEL_WARNING "WARNING"
#define LOG_LEVEL_ERROR "ERROR"

// Function prototypes


// Convenient logging macros
#define LOG(level, message) write_log(level, __FILE__, __LINE__, message)
#define LOG_DEBUG(message) write_log(LOG_LEVEL_DEBUG, __FILE__, __LINE__, message)
#define LOG_INFO(message) write_log(LOG_LEVEL_INFO, __FILE__, __LINE__, message)
#define LOG_WARNING(message) write_log(LOG_LEVEL_WARNING, __FILE__, __LINE__, message)
#define LOG_ERROR(message) write_log(LOG_LEVEL_ERROR, __FILE__, __LINE__, message)

#endif // LOGGING_H