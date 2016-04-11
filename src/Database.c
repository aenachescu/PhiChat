/**
 * @file Database.h
 * @brief Implementation of functions of Database structure.
 */

#include <Database.h>

#include <string.h>

enum PhiChatErrors NewDatabase(__OUT__ struct Database **db,
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

    *db = (struct Database*) malloc(sizeof(struct Database));

    if (*db == NULL)
        return DATABASE_NULL;

    (*db)->sql = NULL;

    (*db)->name = malloc(strlen(name)+1);
    if((*db)->name == NULL)
        return DATABASE_NAME_NULL;
    strcpy((*db)->name, name);

    (*db)->host = malloc(strlen(host)+1);
    if((*db)->host == NULL)
        return DATABASE_HOST_NULL;
    strcpy((*db)->host, host);

    (*db)->user = malloc(strlen(user)+1);
    if((*db)->user == NULL)
        return DATABASE_USER_NULL;
    strcpy((*db)->user, user);

    (*db)->password = malloc(strlen(pw)+1);
    if((*db)->password == NULL)
        return DATABASE_PASSWORD_NULL;
    strcpy((*db)->password, pw);

    return NO_ERROR;
}

enum PhiChatErrors DeleteDatabase(__IN__ struct Database **db)
{
    if(db == NULL)
        return POINTER_NULL;

    if(*db == NULL)
        return DATABASE_NULL;

    if((*db)->sql == NULL)
        return DATABASE_NULL;
    free((*db)->sql);

    if((*db)->name == NULL)
        return DATABASE_NAME_NULL;
    free((*db)->name);

    if((*db)->host == NULL)
        return DATABASE_HOST_NULL;
    free((*db)->host);

    if((*db)->user == NULL)
        return DATABASE_USER_NULL;
    free((*db)->user);

    if((*db)->password == NULL)
        return DATABASE_PASSWORD_NULL;
    free((*db)->password);

    free(*db);
    *db = NULL;

    return NO_ERROR;
}

enum PhiChatErrors InitDatabase(__IN__ struct Database *db)
{
    if (db == NULL)
        return DATABASE_NULL;

    (*db)->sql = mysql_init (NULL);

    if ((*db)->sql == NULL)
    {
        fprintf (stdout, "%s\n", mysql_error((*db)->sql));
        return DATABASE_ERROR_INIT;
    }

    return NO_ERROR;
}

enum PhiChatErrors ConnectToDatabase(__IN__ struct Database *db)
{
    if (db == NULL)
        return DATABASE_NULL;

    if (mysql_real_connect(db->sql, db->host, db->user, db->password, db->name, 0, NULL, 0) == NULL)
    {
        fprintf (stdout, "%s\n", mysql_error((*db)->sql));
        db->sql = NULL;
        return DATABASE_CONNECTION_FAILED;
    }

    return NO_ERROR;
}

enum PhiChatErrors DisconnecFromDatabase(__IN__ struct Database *db)
{
    if (db == NULL)
        return DATABASE_NULL;

    mysql_close(db->sql);
    db->sql = NULL;

    return NO_ERROR;
}
