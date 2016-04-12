/**
 * @file Group.c
 * @brief In this file are implemented the functions for struct Group.
 */

#include <Group.h>

#include <stdlib.h>

enum PhiChatErrors NewGroup(__OUT__ struct Group **group)
{
    if (group == NULL)
        return POINTER_NULL;

    *group = (struct Group*) malloc(sizeof(struct Group));
    if (group == NULL)
        return GROUP_NULL;

    (*group)->running = 0;
    (*group)->clientsNumber = 0;
    for (size_t i = 0; i < MAX_CLIENTS_IN_GROUP; i++)
        (*group)->clients[i] = NULL;

    return NO_ERROR;
}

enum PhiChatErrors DeleteGroup(__IN__ struct Group **group)
{
    if (group == NULL)
        return POINTER_NULL;

    if (*group == NULL)
        return GROUP_NULL;

    if ((*group)->running == 1)
        return GROUP_STILL_RUNS;

    if ((*group)->clientsNumber > 0)
        return GROUP_NOT_EMPTY;

    free(*group);
    *group = NULL;

    return NO_ERROR;
}

enum PhiChatErrors AddClientInGroup(__IN__ struct Group *group,
                                    __IN__ struct Client *client)
{
    if (group == NULL)
        return GROUP_NULL;

    if (client == NULL)
        return CLIENT_NULL;

    if (group->clientsNumber == MAX_CLIENTS_IN_GROUP)
        return GROUP_FULL;

    group->clients[group->clientsNumber] = client;
    group->clientsNumber++;

    return NO_ERROR;
}

enum PhiChatErrors RemoveClientFromGroup(__IN__ struct Group *group,
                                         __IN__ struct Client *client)
{
    if (group == NULL)
        return GROUP_NULL;

    if (client == NULL)
        return CLIENT_NULL;

    if (group->clientsNumber == 0)
        return GROUP_EMPTY;

    for (size_t i = 0; i < group->clientsNumber; i++)
        if (group->clients[i] == client)
        {
            for (size_t j = i + 1; j < group->clientsNumber; j++)
                group->clients[j - 1] = group->clients[j];

            group->clientsNumber--;
            group->clients[group->clientsNumber] = NULL;

            return NO_ERROR;
        }

    return CLIENT_NOT_FOUND;
}

