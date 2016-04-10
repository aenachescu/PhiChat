/**
 * @file Group.h
 * @brief Group structure, as well as helper functions.
 */

#ifndef PhiChat_GROUP
#define PhiChat_GROUP

#include <Defines.h>
#include <Errors.h>
#include <Client.h>

#ifdef __linux
#include <pthread.h>
#endif

struct Group
{
#ifdef __linux
    pthread_t thread;
#endif

    unsigned int clientsNumber;
    uint8_t running;
    struct Client *clients[MAX_CLIENTS_IN_GROUP];
};

enum PhiChatErrors NewGroup(__OUT__ struct Group**);

enum PhiChatErrors DeleteGroup(__IN__ struct Group**);

enum PhiChatErrors AddClientInGroup(__IN__ struct Group*,
                                    __IN__ struct Client*);

enum PhiChatErrors RemoveClientFromGroup(__IN__ struct Group*,
                                         __IN__ struct Client*);

#endif
