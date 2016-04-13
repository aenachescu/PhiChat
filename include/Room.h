/**
 * @file Room.h
 * @brief Room structure, as well as helper functions.
 */

#ifndef PhiChat_ROOM
#define PhiChat_ROOM

#include <ListClients.h>
#include <Defines.h>
#include <Errors.h>

#include <stdint.h>

struct Room
{
    uint64_t id;
    char name[ROOM_MAX_LENGTH_NAME];
    uint8_t status;
    struct ListClients *clients;
};

enum PhiChatErrors NewRoom(__OUT__ struct Room**,
                           __IN__  const uint64_t,
                           __IN__  const uint8_t,
                           __IN__  const char*);

enum PhiChatErrors DeleteRoom(__IN__ struct Room**);

enum PhiChatErrors AddClientInRoom(__IN__ struct Room*,
                                   __IN__ struct Client*);

enum PhiChatErrors RemoveClientFromRoom(__IN__ struct Room*,
                                        __IN__ struct Client*);

#endif

