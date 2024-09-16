#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
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

    return genFilename
}

char createTimeStampFile(const char *filename)
{
    FILE *openFile;
    char *genFilename;

    genFilename = generateFilename(filename);

    if (fopen(genFilename, "r"))
    {
        fclose(genFilename);
        return;
    }

    fopen(genFilename, "a");

    
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

void dirCrawl(const char* path)
{
    WIN32_FIND_DATA findFileData;
    HANDLE hFind = INVALID_HANDLE_VALUE;
    char dirPath[MAX_PATH];
    char fullPath[MAX_PATH];

    snprintf(dirPath, MAX_PATH, "%s\\*", path);

    hFind = FindFirstFile(dirPath, &findFileData);
    if (hFind == INVALID_HANDLE_VALUE)
	{
        printf("FindFirstFile error: %d\n", GetLastError());
        return;
    }

    do {
        if (strcmp(findFileData.cFileName, ".") != 0 && strcmp(findFileData.cFileName, "..") != 0)
		{
            snprintf(fullPath, MAX_PATH, "%s\\%s", path, findFileData.cFileName);
            if (findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
			{
                printf("Directory: %s\n", fullPath);
                dirCrawl(fullPath);
            } else
			{
                printf("File: %s\n", fullPath);
            }
        }
    } while (FindNextFile(hFind, &findFileData) != 0);

    FindClose(hFind);
}

/**[Unix Section]********************************************
 *  														*
 *	This section is the I/O for Apple and Linux systems.	*
 *  														*
 ***********************************************************/
#elif __unix__ || __APPLE__
#include <dirent.h>

void dirCrawl(const char* path)
{
    struct dirent* entry;
    DIR* dir = opendir(path);

    if (dir == NULL) {
        printf("opendir error: %s\n", strerror(errno));
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip "." and ".."
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char fullPath[1024];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", path, entry->d_name);

            struct stat statbuf;
            if (stat(fullPath, &statbuf) == 0) {
                if (S_ISDIR(statbuf.st_mode)) {
                    printf("Directory: %s\n", fullPath);
                    // Recursively crawl subdirectories
                    dirCrawl(fullPath);
                } else {
                    printf("File: %s\n", fullPath);
                }
            } else {
                printf("stat error: %s\n", strerror(errno));
            }
        }
    }

    closedir(dir);
}

/**[Other]***************************************************
 *															*
 *	This is the EOF, if the previous sections were not used	*
 *	then the operating system trying to run the program is	*
 *	not supported.											*
 *															*
 ***********************************************************/
#else
#error "Unsupported platform: Ask github.com/UbiquitousNull for assistance and/or forgiveness."
#endif
