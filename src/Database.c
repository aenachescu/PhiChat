/**
 * @file Database.h
 * @brief Implementation of functions of Database structure.
 */

#include <Database.h>

#include <string.h>

enum PhiChatErrors NewDatabase (__OUT__ struct Database **db,
                                __IN__  const char *name,
                                __IN__  const char *host,
                                __IN__  const char *user,
                                __IN__  const char *pw)
{
    if (db == NULL)
        return POINTER_NULL;

    if (name == NULL)
        return DATABASE_NAME_NULL;

    if (host == NULL)
        return DATABASE_HOST_NULL;

    if (user == NULL)
        return DATABASE_USER_NULL;

    if (pw == NULL)
        return DATABASE_PASSWORD_NULL;

    *db = (struct Database*) malloc (sizeof (struct Database));

    if (*db == NULL)
        return DATABASE_NULL;

    (*db)->sql = NULL;
    (*db)->sql = mysql_init (NULL);

    if ( (*db)->sql == NULL)
    {
        fprintf (stdout, "%s\n", mysql_error ( (*db)->sql));
        return DATABASE_ERROR_INIT;
    }

    strcpy((*db)->name, name);

    strcpy((*db)->host, host);

    strcpy((*db)->user, user);

    strcpy((*db)->password, pw);

    return NO_ERROR;
}
