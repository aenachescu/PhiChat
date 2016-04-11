#include <ListClients.h>
#include <cut.h>

#include <stdlib.h>
#include <time.h>

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
    CUT_CHECK(DeleteNodeListClients(&node) == NO_ERROR);
    CUT_CHECK(node == NULL);

    NewNodeListClients(&node);
    struct Client *client;
    NewClient(&client, 1);
    node->clients[0] = client;
    CUT_CHECK(DeleteNodeListClients(&node) == NODE_NOT_EMPTY);

    struct NodeListClients *node2;
    NewNodeListClients(&node2);
    node->next = node2;
    CUT_CHECK(DeleteNodeListClients(&node) == NODE_NOT_EMPTY);

    DeleteClient(&node->clients[0]);
    CUT_CHECK(DeleteNodeListClients(&node) == NO_ERROR);
    CUT_CHECK(DeleteNodeListClients(&node2) == NO_ERROR);
    CUT_CHECK(node == NULL);
    CUT_CHECK(node2 == NULL);
}

CUT_DEFINE_TEST(AddClientInNodeTest)
{
    struct NodeListClients *node = NULL;
    NewNodeListClients(&node);

    struct Client *clients[MAX_CLIENTS_IN_NODE + 1];
    for (size_t i = 0; i <= MAX_CLIENTS_IN_NODE; i++)
        NewClient(&clients[i], i + 1);

    CUT_CHECK(AddClientInNode(NULL, NULL) != NO_ERROR);
    CUT_CHECK(AddClientInNode(node, NULL) == CLIENT_NULL);
    CUT_CHECK(AddClientInNode(NULL, clients[0]) == NODE_NULL);
    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE; i++)
    {
        CUT_CHECK(AddClientInNode(node, clients[i]) == NO_ERROR);
        CUT_CHECK(node->clientsNumber == i + 1);
        CUT_CHECK(node->clients[i] == clients[i]);
    }
    CUT_CHECK(AddClientInNode(node, clients[MAX_CLIENTS_IN_NODE]) == NODE_FULL);

    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE; i++)
        DeleteClient(&node->clients[i]);
    node->clientsNumber = 0;

    DeleteNodeListClients(&node);
    DeleteClient(&clients[MAX_CLIENTS_IN_NODE]);
}

CUT_DEFINE_TEST(RemoveClientFromNodeTest)
{
    struct NodeListClients *node = NULL;
    struct Client *clients[MAX_CLIENTS_IN_NODE];

    NewNodeListClients(&node);
    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE; i++)
        NewClient(&clients[i], i + 1);

    CUT_CHECK(RemoveClientFromNode(node, NULL) == CLIENT_NULL);
    CUT_CHECK(RemoveClientFromNode(NULL, clients[0]) == NODE_NULL);
    CUT_CHECK(RemoveClientFromNode(NULL, NULL) != NO_ERROR);
    CUT_CHECK(RemoveClientFromNode(node, clients[0]) == NODE_EMPTY);

    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE; i++)
        AddClientInNode(node, clients[i]);

    CUT_CHECK(RemoveClientFromNode(node, clients[0]) == NO_ERROR);
    CUT_CHECK(node->clients[MAX_CLIENTS_IN_NODE - 1] == NULL);
    CUT_CHECK(node->clientsNumber == MAX_CLIENTS_IN_NODE - 1);
    CUT_CHECK(RemoveClientFromNode(node, clients[0]) == CLIENT_NOT_FOUND);

    size_t part1, part2, part3, clientsNumber = MAX_CLIENTS_IN_NODE - 1;
    part1 = MAX_CLIENTS_IN_NODE / 4;
    part2 = MAX_CLIENTS_IN_NODE / 2;
    part3 = 3 * MAX_CLIENTS_IN_NODE / 4;

    for (size_t i = part1; i < part2; i++)
    {
        CUT_CHECK(RemoveClientFromNode(node, clients[i]) == NO_ERROR);
        clientsNumber--;
        CUT_CHECK(node->clientsNumber == clientsNumber);
        for (size_t j = clientsNumber; j < MAX_CLIENTS_IN_NODE; j++)
            CUT_CHECK(node->clients[j] == NULL);
    }

    for (size_t i = part3; i >= part2; i--)
    {
        CUT_CHECK(RemoveClientFromNode(node, clients[i]) == NO_ERROR);
        clientsNumber--;
        CUT_CHECK(node->clientsNumber == clientsNumber);
        for (size_t j = clientsNumber; j < MAX_CLIENTS_IN_NODE; j++)
            CUT_CHECK(node->clients[j] == NULL);
    }

    for (size_t i = part3 + 1; i < MAX_CLIENTS_IN_NODE; i++)
    {
        CUT_CHECK(RemoveClientFromNode(node, clients[i]) == NO_ERROR);
        clientsNumber--;
        CUT_CHECK(node->clientsNumber == clientsNumber);
        for (size_t j = clientsNumber; j < MAX_CLIENTS_IN_NODE; j++)
            CUT_CHECK(node->clients[j] == NULL);
    }

    // i = 1 because clients[0] was removed
    for (size_t i = 1; i < part1; i++)
    {
        CUT_CHECK(RemoveClientFromNode(node, clients[i]) == NO_ERROR);
        clientsNumber--;
        CUT_CHECK(node->clientsNumber == clientsNumber);
        for (size_t j = clientsNumber; j < MAX_CLIENTS_IN_NODE; j++)
            CUT_CHECK(node->clients[j] == NULL);
    }

    DeleteNodeListClients(&node);
    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE; i++)
        DeleteClient(&clients[i]);
}

CUT_DEFINE_TEST(NewListClientsTest)
{
    struct ListClients *list = NULL;

    CUT_CHECK(NewListClients(NULL) == POINTER_NULL);
    CUT_CHECK(NewListClients(&list) == NO_ERROR);
    CUT_CHECK(list != NULL);
    CUT_CHECK(list->head != NULL);
    CUT_CHECK(list->head->next == NULL);

    DeleteListClients(&list);
}

CUT_DEFINE_TEST(DeleteListClientsTest)
{
    struct ListClients *list = NULL;
    CUT_CHECK(DeleteListClients(NULL) == POINTER_NULL);
    CUT_CHECK(DeleteListClients(&list) == LIST_NULL);

    struct Client *clients[5];
    struct NodeListClients *nodes[4];

    NewListClients(&list);
    CUT_CHECK(DeleteListClients(&list) == NO_ERROR);
    CUT_CHECK(list == NULL);

    NewClient(&clients[0], 5);
    NewListClients(&list);
    AddClientInNode(list->head, clients[0]);
    for (int i = 1; i < 5; i++)
    {
        NewClient(&clients[i], i);
        NewNodeListClients(&nodes[i - 1]);
        AddClientInNode(nodes[i - 1], clients[i]);
    }

    list->head->next = nodes[0];
    for (int i = 1; i < 4; i++)
        nodes[i - 1]->next = nodes[i];

    CUT_CHECK(DeleteListClients(&list) == LIST_NOT_EMPTY);

    RemoveClientFromNode(list->head, clients[0]);
    CUT_CHECK(DeleteListClients(&list) == LIST_NOT_EMPTY);
    DeleteClient(&clients[0]);
    for (int i = 1; i < 5; i++)
    {
        RemoveClientFromNode(nodes[i - 1], clients[i]);
        if (i < 4)
            CUT_CHECK(DeleteListClients(&list) == LIST_NOT_EMPTY);
        DeleteClient(&clients[i]);
    }

    CUT_CHECK(DeleteListClients(&list) == NO_ERROR);
    CUT_CHECK(list == NULL);
}

CUT_DEFINE_TEST(AddClientInListTest)
{
    struct Client *clients[MAX_CLIENTS_IN_NODE + 1];
    struct ListClients *list = NULL;

    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE + 1; i++)
        NewClient(&clients[i], i + 1);
    NewListClients(&list);

    CUT_CHECK(AddClientInList(NULL, clients[0]) == LIST_NULL);
    CUT_CHECK(AddClientInList(list, NULL) == CLIENT_NULL);
    CUT_CHECK(AddClientInList(NULL, NULL) != NO_ERROR);

    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE + 1; i++)
        CUT_CHECK(AddClientInList(list, clients[i]) == NO_ERROR);

    struct NodeListClients *node1, *node2;
    node1 = list->head;
    node2 = node1->next;

    CUT_CHECK(node1->clientsNumber == MAX_CLIENTS_IN_NODE);
    CUT_CHECK(node2->clientsNumber == 1);

    enum PhiChatErrors err;
    for (size_t i = 0; i < MAX_CLIENTS_IN_NODE; i++)
    {
        RemoveClientFromNode(node1, clients[i]);
        DeleteClient(&clients[i]);
    }
    RemoveClientFromNode(node2, clients[MAX_CLIENTS_IN_NODE]);
    DeleteClient(&clients[MAX_CLIENTS_IN_NODE]);

    DeleteListClients(&list);
}

CUT_DEFINE_TEST(RemoveClientFromListTest)
{
    struct Client *clients[5 * MAX_CLIENTS_IN_NODE];
    struct ListClients *list = NULL;

    size_t size = 5 * MAX_CLIENTS_IN_NODE;
    for (size_t i = 0; i < size; i++)
        NewClient(&clients[i], i + 1);
    NewListClients(&list);

    CUT_CHECK(RemoveClientFromList(NULL, clients[0]) == LIST_NULL);
    CUT_CHECK(RemoveClientFromList(list, NULL) == CLIENT_NULL);
    CUT_CHECK(RemoveClientFromList(NULL, NULL) != NO_ERROR);

    for (size_t i = 0; i < size; i++)
        AddClientInList(list, clients[i]);

    size_t positions[size], a, b, temp;
    for (size_t i = 0; i < size; i++)
        positions[i] = i;

    srand(time(NULL));
    for (size_t i = 0; i < 1000; i++)
    {
        a = rand() % size;
        b = rand() % size;
        temp = positions[a];
        positions[a] = positions[b];
        positions[b] = temp;
    }

    enum PhiChatErrors err1, err2;
    for (size_t i = 0; i < size; i++)
    {
        CUT_CHECK(RemoveClientFromList(list, clients[positions[i]]) == NO_ERROR);
        CUT_CHECK(RemoveClientFromList(list, clients[positions[i]]) == CLIENT_NOT_FOUND);
        DeleteClient(&clients[positions[i]]);
    }

    DeleteListClients(&list);
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
