#include "utils.h"

FILE* currentLog;

FILE* startLog()
{
	FILE* file;
	if (!(file = createFile("Activity_Log")))
	{
		FATAL_ERR("Failed to create log");
		return NULL; // Fallback — FATAL_ERR already calls main file shutdownTotal function.
	}

	return file;
}

int logLength(FILE* file)
{
	if (!file) return -1;

	long start = ftell(file);
	rewind(file);

	int lines = 0;
	char buffer[MAX_LOG_LENGTH];
	while (fgets(buffer, sizeof(buffer), file))
		lines++;

	fseek(file, start, SEEK_SET);
	return lines;
}

int writeLog(const char* level, const char* file, int line, const char* fmt, ...)
{
	if (!currentLog || logLength(currentLog) > 1000)
	{
		if (currentLog) { fclose(currentLog); }
		currentLog = startLog();
		if (!currentLog)
		{ 
			FATAL_ERR(
				"\n\n\n"
				"How did we get here?\n"
				"Context: The function call before this has an inbuilt error catch and systems shutdown call.\n"
				"SO, that means you have witnessed the impossible!\n"
				"I will now cry because that means C is the issue not me. . .\n"
				"- Jonathan\n\n\n"
			);
			return 0; 
		}
	}

	char message[MAX_LOG_LENGTH];
	va_list args;
	va_start(args, fmt);
	vsnprintf(message, MAX_LOG_LENGTH, fmt, args);
	va_end(args);

	time_t now = time(NULL);
	struct tm* t = localtime(&now);
	char timestamp[20];
	strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", t);

	fprintf(currentLog, "[%s] %s %s:%d: %s\n", level, timestamp, file, line, message);
	fflush(currentLog);

	return 1;
}