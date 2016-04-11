/**
 * @file Server.h
 * @brief Server structure, as well as helper functions.
 */

#ifndef PhiChat_SERVER
#define PhiChat_SERVER

#include <Defines.h>
#include <Errors.h>
#include <HeapGroup.h>

#ifdef __linux
#include <pthread.h>
#endif

struct Server
{
    int socket;
#ifdef __linux
    pthread_t thread;
#endif
    struct HeapGroup *groups;
};

#endif

