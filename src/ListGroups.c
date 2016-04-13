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
    if ((*node)->group == NULL) {
        return GROUP_NULL;
    }

    return NO_ERROR;
}

enum PhiChatErrors DeleteNodeListGroups(__IN__ struct NodeListGroups** node)
{
    return NO_ERROR;
}

enum PhiChatErrors AddClientInNodeListGroups(__IN__ struct NodeListGroups* node,
                                             __IN__ struct Client* client)
{
    return NO_ERROR;
}

enum PhiChatErrors RemoveClientFromNodeListGroups(__IN__ struct NodeListGroups* node,
                                                  __IN__ struct Client* client)
{
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
