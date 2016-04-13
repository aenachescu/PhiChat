#include <Group.h>
#include <Errors.h>
#include <ListGroups.h>

enum PhiChatErrors NewNodeListGroups(__OUT__ struct NodeListGroups** node)
{
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
