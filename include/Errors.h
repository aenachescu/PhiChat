/**
 * @file Errors.h
 * @brief In this file are defined the errors.
 */

#ifndef PhiChat_ERRORS
#define PhiChat_ERRORS

enum PhiChatErrors
{
    NO_ERROR                    =  0,
    POINTER_NULL                = -1,
    CLIENT_NULL                 = -2,
    NAME_NULL                   = -3,
    NAME_TOO_LONG               = -4,
    INVALID_ID                  = -5,
    CLIENT_ALREADY_LOGGED       = -6,
    CLIENT_NOT_LOGGED           = -7,
    INVALID_SOCKET              = -8,
    NODE_NULL                   = -9,
    CLIENT_NOT_NULL             = -10,
    NODE_NOT_NULL               = -11
};

#endif

