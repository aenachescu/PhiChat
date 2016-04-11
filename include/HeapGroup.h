/**
 * @file HeapGroup.h
 * @brief HeapGroup and NodeHeapGroup structures, as well as helper functions.
 */

#ifndef PhiChat_HEAPGROUP
#define PhiChat_HEAPGROUP

#include <Errors.h>
#include <Group.h>

struct NodeHeapGroup
{
    struct Group *group;
    struct NodeHeapGroup *left, *right;
};

struct HeapGroup
{
    struct NodeHeapGroup *root;
};

#endif

