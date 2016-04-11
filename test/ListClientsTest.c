#include <ListClients.h>
#include <cut.h>

CUT_DEFINE_TEST(NewNodeListClientsTest)
{
    struct NodeListClients *node;

    CUT_CHECK(NewNodeListClients(NULL) == POINTER_NULL);
    CUT_CHECK(NewNodeListClients(&node) == NO_ERROR);
    CUT_CHECK(node->clientsNumber == 0);

    CUT_CHECK(node->next == NULL);
    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE; i++)
    {
        CUT_CHECK(node->clients[i] == NULL);
    }

    DeleteNodeListClients(&node);
}

CUT_DEFINE_TEST(DeleteNodeListClientsTest)
{
    struct NodeListClients *node = NULL;

    CUT_CHECK(DeleteNodeListClients(NULL) == POINTER_NULL);
    CUT_CHECK(DeleteNodeListClients(&node) == NODE_NULL);

    NewNodeListClients(&node);
    struct Client *client;
    NewClient(&client, 1);
    node->clients[0] = client;
    CUT_CHECK(DeleteNodeListClients(&node) == NODE_NOT_EMPTY);

    struct NodeListClients *node2;
    NewNodeListClients(&node2);
    node->next = node2;
    CUT_CHECK(DeleteNodeListClients(&node) != NO_ERROR);

    DeleteClient(&node->clients[0]);
    CUT_CHECK(DeleteNodeListClients(&node) == NODE_NOT_NULL);
    CUT_CHECK(DeleteNodeListClients(&node->next) == NO_ERROR);
    CUT_CHECK(DeleteNodeListClients(&node) == NO_ERROR);
}

CUT_DEFINE_TEST(AddClientInNodeTest)
{

}

CUT_DEFINE_TEST(RemoveClientFromNodeTest)
{

}

CUT_DEFINE_TEST(NewListClientsTest)
{

}

CUT_DEFINE_TEST(DeleteListClientsTest)
{

}

CUT_DEFINE_TEST(AddClientInListTest)
{

}

CUT_DEFINE_TEST(RemoveClientFromListTest)
{

}

CUT_DEFINE_MODULE(ListClientsTest)
    CUT_CALL_TEST(NewNodeListClientsTest);
    CUT_CALL_TEST(DeleteNodeListClientsTest);
    CUT_CALL_TEST(AddClientInNodeTest);
    CUT_CALL_TEST(RemoveClientFromNodeTest);
    CUT_CALL_TEST(NewListClientsTest);
    CUT_CALL_TEST(DeleteListClientsTest);
    CUT_CALL_TEST(AddClientInListTest);
    CUT_CALL_TEST(RemoveClientFromListTest);
CUT_END_MODULE
