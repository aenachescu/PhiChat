/**
 * @file ListClients.c
 * @brief In this file are implemented the functions for ListClients and NodeListClients structures.
 */

#include <ListClients.h>

#include <stdlib.h>

enum PhiChatErrors NewNodeListClients (__OUT__ struct NodeListClients **node)
{
    if (node == NULL)
        return POINTER_NULL;

    *node = (struct NodeListClients *) malloc (sizeof (struct NodeListClients));

    if (*node == NULL)
        return NODE_NULL;

    (*node)->next = NULL;
    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE; i++)
        (*node)->clients[i] = NULL;

    (*node)->clientsNumber = 0;

    return NO_ERROR;
}

enum PhiChatErrors DeleteNodeListClients (__IN__ struct NodeListClients **node)
{
    if (node == NULL)
        return POINTER_NULL;

    if (*node == NULL)
        return NODE_NULL;

    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE; i++)
        if ( (*node)->clients[i] != NULL)
            return NODE_NOT_EMPTY;

    if ( (*node)->next != NULL)
        return NODE_NOT_NULL;

    free (*node);
    *node = NULL;

    return NO_ERROR;
}

enum PhiChatErrors AddClientInNode (__IN__ struct NodeListClients *node,
                                    __IN__ struct Client *client)
{
    if (node == NULL)
        return NODE_NULL;

    if (client == NULL)
        return CLIENT_NULL;

    if (node->clientsNumber == MAX_CLIENTS_IN_NODE)
        return NODE_FULL;

    node->clients[node->clientsNumber] = client;

    node->clientsNumber++;

    return NO_ERROR;
}

enum PhiChatErrors RemoveClientFromNode (__IN__ struct NodeListClients *node,
        __IN__ struct Client *client)
{
    if (node == NULL)
        return NODE_NULL;

    if (client == NULL)
        return CLIENT_NULL;

    if (node->clientsNumber == 0)
        return NODE_EMPTY;

    for (size_t i = 0; i < node->clientsNumber - 1; i++)
    {
        if (node->clients[i] == client)
            node->clients[i] = NULL;
        if (node->clients[i] == NULL && node->clients[i + 1] != NULL)
        {
            node->clients[i] = node->clients[i + 1];
            node->clients[i + 1] = NULL;
        }
    }
    if(node->clients[node->clientsNumber-1] == node->clients[node->clientsNumber])
        node->clients[node->clientsNumber] = NULL;
    else
        return CLIENT_NOT_FOUND;

    return NO_ERROR;
}

enum PhiChatErrors NewListClients (__OUT__ struct ListClients **list)
{
    if (list == NULL)
        return POINTER_NULL;

    *list = (struct ListClients *) malloc (sizeof (ListClients));

    if (*list == NULL)
        return LIST_NULL;

    return NewNodeListClients (&list->head);
}

enum PhiChatErrors DeleteListClients (__IN__ struct ListClients **list)
{
    if (list == NULL)
        return POINTER_NULL;

    if (*list == NULL)
        return LIST_NULL;

    enum PhiChatErrors error;
    struct NodeListClients *temp;
    while ( (*list)->head)
    {
        temp = (*list)->head->next;
        error = DeleteNodeListClients (& ( (*list)->head));
        if (error != NO_ERROR)
            return error;
        (*list)->head = temp;
    }

    free (*list);
    *list = NULL;

    return NO_ERROR;
}

enum PhiChatErrors AddClientInList (__IN__ struct ListClients *list,
                                    __IN__ struct Client *client)
{
    if (list == NULL)
        return LIST_NULL;

    if (client == NULL)
        return CLIENT_NULL;

    struct NodeListClients *index = list->head;
    while (index->next)
    {
        if (index->clientsNumber < MAX_CLIENTS_IN_NODE)
            return AddClientInNode (index, client);
        index = index->next;
    }

    if (index->clientsNumber < MAX_CLIENTS_IN_NODE)
        return AddClientInNode (index, client);

    enum PhiChatErrors error = NewNodeClientsList (&index->next);
    if (error != NO_ERROR)
        return error;

    return AddClientInNode (index->next, client);
}

enum PhiChatErrors RemoveClientFromList (__IN__ struct ListClients *list,
        __IN__ struct Client *client)
{
    if (list == NULL)
        return LIST_NULL;

    if (client == NULL)
        return CLIENT_NULL;

    struct NodeListClients *index = list->head;
    enum PhiChatErrors error;
    while (index->next)
    {
        error = RemoveClientFromNode(index, client);
        if(error == NO_ERROR)
            return NO_ERROR;
        else if(error == CLIENT_NOT_FOUND)
            index = index->next;
        else
            return error;
    }

    return RemoveClientFromNode (index, client);
}
