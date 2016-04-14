#include <Group.h>
#include <Errors.h>
#include <ListGroups.h>

#include <stdlib.h>

enum PhiChatErrors NewNodeListGroups(__OUT__ struct NodeListGroups** node)
{
    if (node == NULL)
    {
        return POINTER_NULL;
    }

    (*node) = malloc(sizeof(struct NodeListGroups));
    if ((*node) == NULL)
    {
        return NODE_NULL;
    }
    (*node)->next = NULL;
    (*node)->group = NULL;

    int err = NewGroup(&(*node)->group);
    if (err != NO_ERROR)
    {
        return err;
    }
    if ((*node)->group == NULL)
    {
        return GROUP_NULL;
    }

    return NO_ERROR;
}

enum PhiChatErrors DeleteNodeListGroups(__IN__ struct NodeListGroups** node)
{
    if (node == NULL)
    {
        return POINTER_NULL;
    }

    if ((*node) == NULL)
    {
        return NODE_NULL;
    }

    if ((*node)->group != NULL)
    {
        if (!(*node)->group->clientsNumber)
        {
            int err = DeleteGroup(&(*node)->group);
            if (err != NO_ERROR)
            {
                return err;
            }
        }
        else
        {
            return GROUP_NOT_EMPTY;
        }
    }

    free((*node));
    return NO_ERROR;
}

enum PhiChatErrors AddClientInNodeListGroups(__IN__ struct NodeListGroups* node,
                                             __IN__ struct Client* client)
{
    if (node == NULL)
    {
        return NODE_NULL;
    }

    if (client == NULL)
    {
        return CLIENT_NULL;
    }

    if (node->group == NULL)
    {
        return GROUP_NULL;
    }

    int err = AddClientInGroup(node->group, client);
    if (err != NO_ERROR)
    {
        return err;
    }

    return NO_ERROR;
}

enum PhiChatErrors RemoveClientFromNodeListGroups(__IN__ struct NodeListGroups* node,
                                                  __IN__ struct Client* client)
{
    if (node == NULL)
    {
        return NODE_NULL;
    }

    if (client == NULL)
    {
        return CLIENT_NULL;
    }

    if (node->group == NULL)
    {
        return GROUP_NULL;
    }

    int err = RemoveClientInGroup(node->group, client);
    if (err != NO_ERROR)
    {
        return err;
    }

    return NO_ERROR;
}

enum PhiChatErrors NewListGroups(__OUT__ struct ListGroups** list)
{
    return NO_ERROR;
}

enum PhiChatErrors DeleteListGroups(__IN__ struct ListGroups** list)
{
    return NO_ERROR;
}

enum PhiChatErrors AddClientInListGroups(__IN__ struct ListGroups* list,
                                         __IN__ struct Client* client)
{
    return NO_ERROR;
}

enum PhiChatErrors RemoveClientFromListGroups(__IN__ struct ListGroups* list,
                                              __IN__ struct Client* client)
{
    return NO_ERROR;
}
