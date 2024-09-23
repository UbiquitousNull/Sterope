#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <errno.h>
#include <SDL.h>
#include "utils.h"


/**[NOTE: ]******************************************************************************
 *																						*
 *  This file handles both UNIX and WIN32 io, because I am to lazy to seperate them :)	*
 *																						*
 *	Also this file is still a WORK IN PROGRESS											*
 *																						*
 ***************************************************************************************/


char generateFilename(char *filename)
{
    time_t now;
    struct tm *timeinfo;
    char timestamp[20];
    char genFilename;

    time(&now);
    timeinfo = localtime(&now);

    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H.%M.%S", timeinfo);

    genFilename = (char*)malloc(strlen(timestamp) + strlen(filename) + 2);

    sprintf(filename, "%s_%s", timestamp, genFilename);

    return genFilename;
}

char createFile(const char* filename)
{
    FILE *openFile;

    if (fopen(filename, "r"))
    {
        fclose(filename);
        return NULL;
    }

    openFile = fopen(filename, "a");

    if (!openFile) {
        // To implement | log "Error, io.c System could not create file." 
    }

    return openFile;
}


/**[NOTE: ]******************************************************************************
 *                                                                                      *
 *  The rest of this is for the directory crawler.                                      *
 *                                                                                      *
 ***************************************************************************************/


/**[Windows Section]*****************************************
 *  														*
 *	This section is the I/O for windows systems.			*
 *  														*
 ***********************************************************/
#ifdef _WIN32
#define snprintf _snprintf
#include <windows.h>

char* dirCrawl(const char* path)
{
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    char dirPath[MAX_PATH];
    char fullPath[MAX_PATH];

    if (snprintf(dirPath, MAX_PATH, "%s\\*", path) >= MAX_PATH) {
        // To implement | log "Error, Path too long: path);
        return;
    }

    hFind = FindFirstFile(dirPath, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        // To implement | log "Error, FindFirstFile error: GetLastError()"
        return;
    }

    do {
        if (strcmp(findFileData.cFileName, ".") == 0 || strcmp(findFileData.cFileName, "..") == 0) { continue; }
		if (snprintf(fullPath, MAX_PATH, "%s\\%s", path, findFileData.cFileName) >= MAX_PATH) {
			// To implement | log "Full path too long: path, findFileData.cFileName"
			continue;
		}

		if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
			printf("Directory: %s\n", fullPath);
			dirCrawl(fullPath);
		} else {
			// To implement | log "File: fullPath"
			return fullPath;
		}
    } while (FindNextFile(hFind, &findFileData));

    if (GetLastError() != ERROR_NO_MORE_FILES) {
        // To implement | log "Error, FindNextFile error: GetLastError();"
    }

    FindClose(hFind);
}

/**[Unix Section]********************************************
 *  														*
 *	This section is the I/O for Apple and Linux systems.	*
 *  														*
 ***********************************************************/
#elif __unix__ || __APPLE__
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>

char* dirCrawl(const char* path)
{
    struct dirent* entry;
    DIR* dir = opendir(path);

    if (dir == NULL) {
        perror("opendir error");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
		char fullPath[PATH_MAX];

        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) { continue; }
        
		if (snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name) >= sizeof(fullPath)) {
			// To implement | log "Error, Path too long: path, entry->d_name"
			continue;
		}
				
		struct stat statbuf;
		if (stat(fullPath, &statbuf) != 0) {
			// To implement | log "Error, stat error for fullPath, strerror(errno)"
			continue;
		}

		if (S_ISDIR(statbuf.st_mode)) {
			// To implement | log "Directory: fullPath"
			// Recursively crawl subdirectories
			dirCrawl(fullPath);
		} else {
			
		}
		
		
    }

    if (closedir(dir) == -1) {
        // To implement | log "closedir error"
    }
}

/**[Other]***************************************************
 *															*
 *	This is the EOF, if the previous sections were not used	*
 *	then the operating system trying to run the program is	*
 *	not supported.											*
 *															*
 ***********************************************************/
#else
#error "io.c | Unsupported platform: Ask UbiquitousNull for assistance and/or forgiveness."
#endif
