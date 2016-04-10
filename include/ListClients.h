/**
 * @file ListClients.h
 * @brief ListClients and NodeListClients structures, as well as helper functions.
 */

#ifndef PhiChat_LISTCLIENTS
#define PhiChat_LISTCLIENTS

#include <Errors.h>
#include <Defines.h>
#include <Client.h>

#include <stdint.h>

struct NodeListClients
{
    uint64_t clientsNumber;
    struct NodeListClients *next;
    struct Client *clients[MAX_CLIENTS_IN_NODE];
};

struct ListClients
{
    struct NodeListClients *head;
};


enum PhiChatErrors NewNodeListClients(__OUT__ struct NodeListClients**);

enum PhiChatErrors DeleteNodeListClients(__IN__ struct NodeListClients**);

enum PhiChatErrors AddClientInNode(__IN__ struct NodeListClients*,
                                   __IN__ struct Client*);

enum PhiChatErrors RemoveClientFromNode(__IN__ struct NodeListClients*,
                                        __IN__ struct Client*);




enum PhiChatErrors NewListClients(__OUT__ struct ListClients**);

enum PhiChatErrors DeleteListClients(__IN__ struct ListClients**);

enum PhiChatErrors AddClientInList(__IN__ struct ListClients*,
                                   __IN__ struct Client*);

enum PhiChatErrors RemoveClientFromList(__IN__ struct ListClients*,
                                        __IN__ struct Client*);

#endif

