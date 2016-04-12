/**
 * @file Database.h
 * @brief Database structure, as well as helper function.
 */

#ifndef PhiChat_DATABASE
#define PhiChat_DATABASE

#include <mysql/mysql.h>

#include <Errors.h>
#include <Defines.h>

struct Database
{
    MYSQL *sql;
    char *name;
    char *host;
    char *user;
    char *password;
};

enum PhiChatErrors NewDatabase(__OUT__ struct Database**,
                               __IN__  const char*,
                               __IN__  const char*,
                               __IN__  const char*,
                               __IN__  const char*);

enum PhiChatErrors DeleteDatabase(__IN__ struct Database**);

enum PhiChatErrors InitDatabase(__IN__ struct Database*);

enum PhiChatErrors ConnectToDatabase(__IN__ struct Database*);

enum PhiChatErrors DisconnecFromDatabase(__IN__ struct Database*);

#endif

