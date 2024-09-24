#ifndef IO_H
#define IO_H

#include <stdio.h>

FILE* createFile(const char *filename);
char* dirCrawl(const char* path);

#endif // IO_H