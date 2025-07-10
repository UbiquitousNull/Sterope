#ifndef UTILS_H
#define UTILS_H

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define RETURN_ERR(...) { fprintf(stderr, __VA__ARGS__); exit(); }

#include "Logging.h"
#include "io.h"

#endif // UTILS_H