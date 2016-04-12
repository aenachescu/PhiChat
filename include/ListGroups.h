/**
 * @file ListGroups.h
 * @brief ListGroups and NodeListGroups structures, as well as helper functions.
 */

#ifndef PhiChat_LISTGROUPS
#define PhiChat_LISTGROUPS

#include <Group.h>
#include <Errors.h>

struct NodeListGroups
{
    struct NodeListGroups *next;
    struct Group *group;
};

struct ListGroups
{
    struct NodeListGroups *head;
};

enum PhiChatErrors NewNodeListGroups(__OUT__ struct NodeListGroups**);

enum PhiChatErrors DeleteNodeListGroups(__IN__ struct NodeListGroups**);

enum PhiChatErrors AddClientInNodeListGroups(__IN__ struct NodeListGroups*,
                                             __IN__ struct Client*);

enum PhiChatErrors RemoveClientFromNodeListGroups(__IN__ struct NodeListGroups*,
                                                  __IN__ struct Client*);

enum PhiChatErrors NewListGroups(__OUT__ struct ListGroups**);

enum PhiChatErrors DeleteListGroups(__IN__ struct ListGroups**);

enum PhiChatErrors AddClientInListGroups(__IN__ struct ListGroups*,
                                         __IN__ struct Client*);

enum PhiChatErrors RemoveClientFromListGroups(__IN__ struct ListGroups*,
                                              __IN__ struct Client*);

#endif

