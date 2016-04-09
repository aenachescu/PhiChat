/**
 * @file Server.h
 * @brief Server structure, as well as helper functions.
 */

#ifndef PhiChat_SERVER
#define PhiChar_SERVER

#include <Defines.h>
#include <Errors.h>
#include <HeapGroup.h>

struct Server
{
    struct HeapGroup *groups;
};

#endif

