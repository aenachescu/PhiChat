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
    CLIENT_NOT_FOUND            = -9,

    GROUP_NULL                  = -10,
    GROUP_NOT_EMPTY             = -11,
    GROUP_STILL_RUNS            = -12,
    GROUP_FULL                  = -13,
    GROUP_EMPTY                 = -14,

    NODE_NULL                   = -15,
    NODE_NOT_EMPTY              = -16,
    NODE_FULL                   = -17,
    NODE_EMPTY                  = -18,

    LIST_NULL                   = -19,
    LIST_NOT_EMPTY              = -20,

    CONFIG_NULL                 = -21,
    CONFIG_UNEXPECTED           = -22,
    CONFIG_EXPECTED_ASSIGN      = -23,
    CONFIG_INTEGER_EXPECTED     = -24,
    CONFIG_EXPECTED_IDENTIFIER  = -25,
    CONFIG_FILENAME_NULL        = -26,

    DATABASE_NAME_NULL          = -27,
    DATABASE_HOST_NULL          = -28,
    DATABASE_USER_NULL          = -29,
    DATABASE_PASSWORD_NULL      = -30,
    DATABASE_NULL               = -31,
    DATABASE_ERROR_INIT         = -32,
    DATABASE_CONNECTION_FAILED  = -33,
    DATABASE_STILL_OPENED       = -34,
    DATABASE_MYSQL_NULL         = -35
};

#endif
