/**
 * @file Config.h
 * @brief Config structure, as well as helper functions.
 */

#ifndef PhiChat_CONFIG
#define PhiChat_CONFIG

struct Config
{
    int *port;
    unsigned long long int *maxConnections;

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
}

#endif
