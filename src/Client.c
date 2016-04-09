/**
 * @file Client.c
 * @brief In this file are implemented the functions for struct Client.
 */

#include <Client.h>

#include <stdlib.h>
#include <string.h>

enum PhiChatErrors NewClient(__OUT__ struct Client **newClient,
                             __IN__  const char *name,
                             __IN__  const uint32_t socket)
{
    if (newClient == NULL)
        return POINTER_NULL;
    if (name == NULL)
        return NAME_NULL;
    if (socket == 0)
        return INVALID_SOCKET;

    size_t length = strlen(name);

    if (length >= MAX_LENGTH_NAME)
        return NAME_TOO_LONG;

    *newClient = (struct Client*) malloc(sizeof(struct Client));
    if (*newClient == NULL)
        return CLIENT_NULL;

    (*newClient)->socket = socket;
    (*newClient)->id     = 0;
    (*newClient)->logged = 0;
    memcpy((*newClient)->name, name, length + 1);

    return NO_ERROR;
}

enum PhiChatErrors DeleteClient(__IN__ struct Client **client)
{
    if (client == NULL)
        return POINTER_NULL;
    if (*client == NULL)
        return CLIENT_NULL;

    free(*client);
    *client = NULL;

    return NO_ERROR;
}

enum PhiChatErrors Login(__IN__ struct Client *client,
                         __IN__ const uint64_t id)
{
    if (client == NULL)
        return CLIENT_NULL;

    if (id == 0)
        return INVALID_ID;

    if (client->logged == 1)
        return CLIENT_ALREADY_LOGGED;

    if (client->id != 0)
        return INVALID_ID;

    client->logged = 1;
    client->id     = id;

    return NO_ERROR;
}

enum PhiChatErrors Logout(__IN__ struct Client *client)
{
    if (client == NULL)
        return CLIENT_NULL;

    if (client->logged == 0)
        return CLIENT_NOT_LOGGED;

    if (client->id == 0)
        return INVALID_ID;

    client->logged = 0;
    client->id     = 0;

    return NO_ERROR;
}

