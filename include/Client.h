/**
 * @file Client.h
 * @brief Client structure, as well as helper functions.
 */

#ifndef PhiChat_CLIENT
#define PhiChat_CLIENT

#include <Defines.h>
#include <Errors.h>

#include <stdint.h>

struct Client
{
    char name[MAX_LENGTH_NAME];
    uint8_t logged;
    uint32_t socket;
    uint64_t id;
};

enum PhiChatErrors NewClient(__OUT__ struct Client**,
                             __IN__  const uint32_t socket);

enum PhiChatErrors DeleteClient(__IN__ struct Client**);

enum PhiChatErrors Login(__IN__ struct Client*,
                         __IN__ const char *name,
                         __IN__ const uint64_t id);

enum PhiChatErrors Logout(__IN__ struct Client*);

#endif

