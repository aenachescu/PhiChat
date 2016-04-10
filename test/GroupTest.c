#include <Group.h>
#include <cut.h>
#include <stdio.h>

CUT_DEFINE_TEST(NewGroupTest)
{
    struct Group *group = NULL;

    CUT_CHECK(NewGroup(NULL) == POINTER_NULL);
    CUT_CHECK(NewGroup(&group) == NO_ERROR);
    CUT_CHECK(group->running == 0);
    CUT_CHECK(group->clientsNumber == 0);
    for (size_t i = 0; i < MAX_CLIENTS_IN_GROUP; i++)
        CUT_CHECK(group->clients[i] == NULL);

    DeleteGroup(&group);
}

CUT_DEFINE_TEST(DeleteGroupTest)
{
    struct Group *group = NULL;

    CUT_CHECK(DeleteGroup(NULL) == POINTER_NULL);
    CUT_CHECK(DeleteGroup(&group) == GROUP_NULL);

    NewGroup(&group);

    group->running = 1;
    CUT_CHECK(DeleteGroup(&group) == GROUP_STILL_RUNS);

    group->clientsNumber = 1;
    CUT_CHECK(DeleteGroup(&group) != NO_ERROR);

    group->running = 0;
    CUT_CHECK(DeleteGroup(&group) == GROUP_NOT_EMPTY);

    group->clientsNumber = 0;
    CUT_CHECK(DeleteGroup(&group) == NO_ERROR);
}

CUT_DEFINE_TEST(AddClientInGroupTest)
{
    struct Group *group = NULL;
    NewGroup(&group);

    struct Client *clients[MAX_CLIENTS_IN_GROUP + 1];
    for (size_t i = 0; i <= MAX_CLIENTS_IN_GROUP; i++)
        NewClient(&clients[i], i + 1);

    CUT_CHECK(AddClientInGroup(NULL, NULL) != NO_ERROR);
    CUT_CHECK(AddClientInGroup(group, NULL) == CLIENT_NULL);
    CUT_CHECK(AddClientInGroup(NULL, clients[0]) == GROUP_NULL);
    for (size_t i = 0; i < MAX_CLIENTS_IN_GROUP; i++)
    {
        CUT_CHECK(AddClientInGroup(group, clients[i]) == NO_ERROR);
        CUT_CHECK(group->clientsNumber == i + 1);
        CUT_CHECK(group->clients[i] == clients[i]);
    }
    CUT_CHECK(AddClientInGroup(group, clients[MAX_CLIENTS_IN_GROUP]) == GROUP_FULL);

    for (size_t i = 0; i < MAX_CLIENTS_IN_GROUP; i++)
        DeleteClient(&group->clients[i]);
    group->clientsNumber = 0;

    DeleteGroup(&group);
    DeleteClient(&clients[MAX_CLIENTS_IN_GROUP]);
}

CUT_DEFINE_TEST(RemoveClientFromGroupTest)
{
    struct Group *group = NULL;
    struct Client *clients[MAX_CLIENTS_IN_GROUP];

    NewGroup(&group);
    for (size_t i = 0; i < MAX_CLIENTS_IN_GROUP; i++)
        NewClient(&clients[i], i + 1);

    CUT_CHECK(RemoveClientFromGroup(group, NULL) == CLIENT_NULL);
    CUT_CHECK(RemoveClientFromGroup(NULL, clients[0]) == GROUP_NULL);
    CUT_CHECK(RemoveClientFromGroup(NULL, NULL) != NO_ERROR);
    CUT_CHECK(RemoveClientFromGroup(group, clients[0]) == GROUP_EMPTY);

    for (size_t i = 0; i < MAX_CLIENTS_IN_GROUP; i++)
        AddClientInGroup(group, clients[i]);

    CUT_CHECK(RemoveClientFromGroup(group, clients[0]) == NO_ERROR);
    CUT_CHECK(group->clients[MAX_CLIENTS_IN_GROUP - 1] == NULL);
    CUT_CHECK(group->clientsNumber == MAX_CLIENTS_IN_GROUP - 1);
    CUT_CHECK(RemoveClientFromGroup(group, clients[0]) == CLIENT_NOT_FOUND);

    size_t part1, part2, part3, clientsNumber = MAX_CLIENTS_IN_GROUP - 1;
    part1 = MAX_CLIENTS_IN_GROUP / 4;
    part2 = MAX_CLIENTS_IN_GROUP / 2;
    part3 = 3 * MAX_CLIENTS_IN_GROUP / 4;

    for (size_t i = part1; i < part2; i++)
    {
        CUT_CHECK(RemoveClientFromGroup(group, clients[i]) == NO_ERROR);
        clientsNumber--;
        CUT_CHECK(group->clientsNumber == clientsNumber);
        for (size_t j = clientsNumber; j < MAX_CLIENTS_IN_GROUP; j++)
            CUT_CHECK(group->clients[j] == NULL);
    }

    for (size_t i = part3; i >= part2; i--)
    {
        CUT_CHECK(RemoveClientFromGroup(group, clients[i]) == NO_ERROR);
        clientsNumber--;
        CUT_CHECK(group->clientsNumber == clientsNumber);
        for (size_t j = clientsNumber; j < MAX_CLIENTS_IN_GROUP; j++)
            CUT_CHECK(group->clients[j] == NULL);
    }

    for (size_t i = part3 + 1; i < MAX_CLIENTS_IN_GROUP; i++)
    {
        CUT_CHECK(RemoveClientFromGroup(group, clients[i]) == NO_ERROR);
        clientsNumber--;
        CUT_CHECK(group->clientsNumber == clientsNumber);
        for (size_t j = clientsNumber; j < MAX_CLIENTS_IN_GROUP; j++)
            CUT_CHECK(group->clients[j] == NULL);
    }

    // i = 1 because clients[0] was removed
    for (size_t i = 1; i < part1; i++)
    {
        CUT_CHECK(RemoveClientFromGroup(group, clients[i]) == NO_ERROR);
        clientsNumber--;
        CUT_CHECK(group->clientsNumber == clientsNumber);
        for (size_t j = clientsNumber; j < MAX_CLIENTS_IN_GROUP; j++)
            CUT_CHECK(group->clients[j] == NULL);
    }

    DeleteGroup(&group);
    for (size_t i = 0; i < MAX_CLIENTS_IN_GROUP; i++)
        DeleteClient(&clients[i]);
}

CUT_DEFINE_MODULE(GroupTest)
    CUT_CALL_TEST(NewGroupTest);
    CUT_CALL_TEST(DeleteGroupTest);
    CUT_CALL_TEST(AddClientInGroupTest);
    CUT_CALL_TEST(RemoveClientFromGroupTest);
CUT_END_MODULE

