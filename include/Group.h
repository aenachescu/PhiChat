/**
 * @file Group.h
 * @brief Group structure, as well as helper functions.
 */

#ifndef PhiChat_GROUP
#define PhiChat_GROUP

#include <Defines.h>
#include <Errors.h>
#include <Client.h>
#include <pthread.h>

struct Group
{
    unsigned int ClientsNumber;
    struct Client *Clients[MAX_CLIENTS_IN_GROUP];
    pthread_t Thread;
};

#endif
