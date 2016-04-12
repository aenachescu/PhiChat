/**
 * @file Server.h
 * @brief Server structure, as well as helper functions.
 */

#ifndef PhiChat_SERVER
#define PhiChat_SERVER

#include <Defines.h>
#include <Errors.h>
#include <ListGroups.h>
#include <Database.h>

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
    struct Database *database;
};

enum PhiChatErrors NewServer(__OUT__ struct Server**,
                             __IN__  struct Database*);

enum PhiChatErrors DeleteServer(__IN__ struct Server**);

enum PhiChatErrors StartServer(__IN__ struct Server*);

enum PhiChatErrors StopServer(__IN__ struct Server*);

#endif

