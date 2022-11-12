#pragma once
#include <cstddef>
#include <cstdint>
#include <cstdlib>

struct Node
{
    int value;
    Node *left;
    Node *right;
};

using Tree = Node *;
