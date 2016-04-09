/**
 * @file ListClients.c
 * @brief In this file are implemented the functions for ListClients and NodeListClients structures.
 */

#include <ListClients.h>

#include <stdlib.h>

enum PhiChatErrors NewNodeListClients(__OUT__ struct NodeListClients** node)
{
    if (node == NULL)
        return POINTER_NULL;

    *node = (struct NodeListClients*) malloc(sizeof(struct NodeListClients));

    if (*node == NULL)
        return NODE_NULL;

    (*node)->next = NULL;
    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE; i++)
        (*node)->clients[i] = NULL;

    return NO_ERROR;
}

enum PhiChatErrors DeleteNodeListClients(__IN__ struct NodeListClients** node)
{
    if(node == NULL)
        return POINTER_NULL;

    if(*node == NULL)
        return NODE_NULL;

    for(size_t i = 0; i < MAX_CLIENTS_IN_NODE; i++)
        if((*node)->clients[i] != NULL)
            return CLIENT_NOT_NULL;

    if((*node)->next != NULL)
        return NODE_NOT_NULL;

    free(*node);
    *node = NULL;

    return NO_ERROR;
}
