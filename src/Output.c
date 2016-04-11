/**
 * @file Errors.c
 * @brief In this file are defined the helper functions for output.
 */

#include <Output.h>

#include <stdio.h>
#include <time.h>

static FILE *terminal = NULL;
static FILE *logfile  = NULL;

void InitOutput(void)
{
    terminal = stdout;
}

void ActivatesTerminal(void)
{
    terminal = stdout;
}

void DeactivatesTerminal(void)
{
    terminal = NULL;
}

void PrintMessage(__IN__ const char *message)
{
    if (message == NULL)
        return;

    time_t timer;
    char buffer[24];
    struct tm* tm_info;
    time(&timer);
    tm_info = localtime(&timer);
    strftime(buffer, 24, "%Y:%m:%d %H:%M:%S : ", tm_info);

    if (terminal != NULL)
    {
        printf(buffer);
        printf(message);
    }

    if (logfile != NULL)
    {
        fprintf(logfile, buffer);
        fprintf(logfile, message);
    }
}

void PrintError(__IN__ enum PhiChatErrors err,
                __IN__ size_t line,
                __IN__ const char *file)
{
    printf("Error: %d\tLine: %zd\tFile: %s\n", err, line, file);
}

