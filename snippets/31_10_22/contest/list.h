#pragma once
#include <cstdint>
#include <cstddef>
#include <cstdlib>

struct Node
{
    int value;
    Node *next;
};

using List = Node *;

struct ListUncons
{
    Node *head;
    List tail;
};
