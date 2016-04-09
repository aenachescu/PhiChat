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

#endif

