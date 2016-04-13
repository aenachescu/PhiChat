#include <Database.h>
#include <cut.h>

#include <string.h>

#define NAME "PhiChatDB"
#define HOST "localhost"
#define USER "PhiChatUser"
#define PASS "PhiChatPassword"

CUT_DEFINE_TEST(NewDatabaseTest)
{
    struct Database *db = NULL;

    CUT_CHECK(NewDatabase(NULL, "name", "host", "user", "pass") == POINTER_NULL);
    CUT_CHECK(NewDatabase(&db, NULL, "host", "user", "pass") == DATABASE_NAME_NULL);
    CUT_CHECK(NewDatabase(&db, "name", NULL, "user", "pass") == DATABASE_HOST_NULL);
    CUT_CHECK(NewDatabase(&db, "name", "host", NULL, "pass") == DATABASE_USER_NULL);
    CUT_CHECK(NewDatabase(&db, "name", "host", "user", NULL) == DATABASE_PASSWORD_NULL);
    CUT_CHECK(NewDatabase(NULL, NULL, NULL, NULL, NULL) != NO_ERROR);

    CUT_CHECK(NewDatabase(&db, "name", "host", "user", "pass") == NO_ERROR);
    CUT_CHECK(db != NULL);
    CUT_CHECK(strcmp(db->name, "name") == 0);
    CUT_CHECK(strcmp(db->host, "host") == 0);
    CUT_CHECK(strcmp(db->user, "user") == 0);
    CUT_CHECK(strcmp(db->password, "pass") == 0);
    CUT_CHECK(db->sql == NULL);

    DeleteDatabase(&db);
}

CUT_DEFINE_TEST(DeleteDatabaseTest)
{
    struct Database *db = NULL;

    CUT_CHECK(DeleteDatabase(NULL) == POINTER_NULL);
    CUT_CHECK(DeleteDatabase(&db) == DATABASE_NULL);

    NewDatabase(&db, NAME, HOST, USER, PASS);
    db->sql = mysql_init(NULL);

    CUT_CHECK(DeleteDatabase(&db) == DATABASE_STILL_OPENED);

    mysql_close(db->sql);
    db->sql = NULL;

    CUT_CHECK(DeleteDatabase(&db) == NO_ERROR);
    CUT_CHECK(db == NULL);
}

CUT_DEFINE_TEST(InitDatabaseTest)
{
    struct Database *db = NULL;
    NewDatabase(&db, NAME, HOST, USER, PASS);

    CUT_CHECK(InitDatabase(NULL) == DATABASE_NULL);
    CUT_CHECK(InitDatabase(db) == NO_ERROR);
    CUT_CHECK(db->sql != NULL);

    mysql_close(db->sql);
    db->sql = NULL;
    DeleteDatabase(&db);
}

CUT_DEFINE_TEST(ConnectToDatabaseTest)
{
    struct Database *db = NULL;

    CUT_CHECK(ConnectToDatabase(db) == DATABASE_NULL);

    NewDatabase(&db, NAME, HOST, USER, PASS);
    CUT_CHECK(ConnectToDatabase(db) == DATABASE_MYSQL_NULL);

    db->sql = mysql_init(NULL);
    CUT_CHECK(ConnectToDatabase(db) == NO_ERROR);

    mysql_close(db->sql);
    db->sql = NULL;
    DeleteDatabase(&db);
}

CUT_DEFINE_TEST(DisconnectFromDatabaseTest)
{
    struct Database *db = NULL;

    CUT_CHECK(DisconnectFromDatabase(db) == DATABASE_NULL);

    NewDatabase(&db, NAME, HOST, USER, PASS);
    CUT_CHECK(DisconnectFromDatabase(db) == DATABASE_MYSQL_NULL);

    db->sql = mysql_init(NULL);
    CUT_CHECK(DisconnectFromDatabase(db) == NO_ERROR);
    CUT_CHECK(db->sql == NULL);

    DeleteDatabase(&db);
}

CUT_DEFINE_MODULE(DatabaseTest)
    CUT_CALL_TEST(NewDatabaseTest);
    CUT_CALL_TEST(DeleteDatabaseTest);
    CUT_CALL_TEST(InitDatabaseTest);
    CUT_CALL_TEST(ConnectToDatabaseTest);
    CUT_CALL_TEST(DisconnectFromDatabaseTest);
CUT_END_MODULE
