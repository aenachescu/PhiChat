#include <Client.h>
#include <cut.h>
#include <string.h>

CUT_DEFINE_TEST(NewClientTest)
{
    struct Client *client;
    CUT_CHECK(NewClient(NULL, "test", 1) == POINTER_NULL);
    CUT_CHECK(NewClient(&client, NULL, 1) == NAME_NULL);
    CUT_CHECK(NewClient(&client, "test", 0) == INVALID_SOCKET);
    CUT_CHECK(NewClient(NULL, NULL, 0) != NO_ERROR);
    CUT_CHECK(NewClient(&client, NULL, 0) != NO_ERROR);
    CUT_CHECK(NewClient(NULL, "test", 0) != NO_ERROR);
    CUT_CHECK(NewClient(NULL, NULL, 1) != NO_ERROR);

    CUT_CHECK(NewClient(&client, "test", 1) == NO_ERROR);
    CUT_CHECK(client->socket == 1);
    CUT_CHECK(client->id == 0);
    CUT_CHECK(client->logged == 0);
    CUT_CHECK(strcmp(client->name, "test") == 0);

    DeleteClient(&client);
}

CUT_DEFINE_TEST(DeleteClientTest)
{
    struct Client *client = NULL;
    CUT_CHECK(DeleteClient(NULL) == POINTER_NULL);
    CUT_CHECK(DeleteClient(&client) == CLIENT_NULL);
    NewClient(&client, "test", 1);
    CUT_CHECK(DeleteClient(&client) == NO_ERROR);
    CUT_CHECK(client == NULL);
}

CUT_DEFINE_MODULE(ClientTest)
    CUT_CALL_TEST(NewClientTest);
    CUT_CALL_TEST(DeleteClientTest);
CUT_END_MODULE

