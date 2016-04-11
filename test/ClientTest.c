#include <Client.h>
#include <cut.h>
#include <string.h>

CUT_DEFINE_TEST(NewClientTest)
{
    struct Client *client;
    CUT_CHECK(NewClient(NULL, 1) == POINTER_NULL);
    CUT_CHECK(NewClient(&client, 0) == INVALID_SOCKET);
    CUT_CHECK(NewClient(NULL, 0) != NO_ERROR);

    CUT_CHECK(NewClient(&client, 1) == NO_ERROR);
    CUT_CHECK(client->socket == 1);
    CUT_CHECK(client->id == 0);
    CUT_CHECK(client->logged == 0);
    CUT_CHECK(strlen(client->name) == 0);

    DeleteClient(&client);
}

CUT_DEFINE_TEST(DeleteClientTest)
{
    struct Client *client = NULL;
    CUT_CHECK(DeleteClient(NULL) == POINTER_NULL);
    CUT_CHECK(DeleteClient(&client) == CLIENT_NULL);
    NewClient(&client, 1);
    CUT_CHECK(DeleteClient(&client) == NO_ERROR);
    CUT_CHECK(client == NULL);
}

CUT_DEFINE_TEST(LoginTest)
{
    struct Client *client = NULL;
    NewClient(&client, 1);

    CUT_CHECK(Login(NULL, "test", 10) == CLIENT_NULL);
    CUT_CHECK(Login(client, "test", 0) == INVALID_ID);
    CUT_CHECK(Login(client, NULL, 10) == NAME_NULL)
    CUT_CHECK(Login(NULL, "test", 0) != NO_ERROR);
    CUT_CHECK(Login(NULL, NULL, 10) != NO_ERROR);
    CUT_CHECK(Login(client, NULL, 0) != NO_ERROR);

    CUT_CHECK(Login(client, "test", 10) == NO_ERROR);
    CUT_CHECK(client->logged == 1);
    CUT_CHECK(client->id == 10);
    CUT_CHECK(strcmp(client->name, "test") == 0);

    CUT_CHECK(Login(client, "test", 20) == CLIENT_ALREADY_LOGGED);

    DeleteClient(&client);
}

CUT_DEFINE_TEST(LogoutTest)
{
    struct Client *client = NULL;
    NewClient(&client, 1);
    Login(client, "test", 10);

    CUT_CHECK(Logout(NULL) == CLIENT_NULL);
    CUT_CHECK(Logout(client) == NO_ERROR);
    CUT_CHECK(client->logged == 0);
    CUT_CHECK(client->id == 0);
    CUT_CHECK(strlen(client->name) == 0);
    CUT_CHECK(Logout(client) == CLIENT_NOT_LOGGED);

    DeleteClient(&client);
}

CUT_DEFINE_MODULE(ClientTest)
    CUT_CALL_TEST(NewClientTest);
    CUT_CALL_TEST(DeleteClientTest);
    CUT_CALL_TEST(LoginTest);
    CUT_CALL_TEST(LogoutTest);
CUT_END_MODULE

