/**
 * @file ListClients.h
 * @brief ListClients and NodeListClients structures, as well as helper functions.
 */

#ifndef PhiChat_LISTCLIENTS
#define PhiChat_LISTCLIENTS

#include <Errors.h>
#include <Defines.h>
#include <Client.h>

struct NodeListClients
{
    struct NodeListClients *next;
    struct Client *clients[MAX_CLIENTS_IN_NODE];
};

struct ListClients
{
    struct NodeListClients *head;
};

#endif

