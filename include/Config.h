/**
 * @file Config.h
 * @brief Config structure, as well as helper functions.
 */

#ifndef PhiChat_CONFIG
#define PhiChat_CONFIG

#include <Errors.h>
#include <Defines.h>

struct Config
{
    int port;
    unsigned long long int maxConnections;

    char *databaseHost;
    char *databaseUser;
    char *databasePassword;
    char *databaseName;

    char *logfileName;
    /**
     * 0 = nothing
     * 1 = date
     * 2 = increment
     */
    int end;
    unsigned long long int respawn;
};

enum PhiChatErrors NewConfig(__OUT__ struct Config**);

enum PhiChatErrors DeleteConfig(__IN__ struct Config**);

enum PhiChatErrors ReadConfig(__IN__ struct Config*, __IN__ const char*);

#endif
