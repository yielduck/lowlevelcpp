#pragma once
#include <cstdlib>
namespace list
{

struct Node
{
    int value;
    Node *next;
};

using List = Node *;

inline List cons(int const value, List const next)
{
    Node * const node = static_cast<Node *>(std::malloc(sizeof(Node)));
    node->value = value;
    node->next = next;
    return node;
}
inline List prepend(Node * const head, List const tail)
{
    head->next = tail;
    return head;
}

struct ListUncons
{
    Node *head;
    List tail;
};
inline ListUncons uncons(List const list)
{
    return {list, list->next};
}

inline void destroy(List const list)
{
    if(list != nullptr)
    {
        destroy(list->next);
        std::free(list);
    }
}
inline List create(int const * const begin, int const * const end)
{
    return begin == end
        ? nullptr
        : cons(*begin, create(begin + 1, end));
}

inline unsigned int length(List const list)
{
    return list == nullptr
        ? 0u
        : 1u + length(list->next);
}
inline List reverse(List list)
{
    List accum = nullptr;
    while(list != nullptr)
    {
        ListUncons const u = uncons(list);
        accum = prepend(u.head, accum);
        list = u.tail;
    }
    return accum;
}
inline List concat(List const left, List const right)
{
    if(left == nullptr)
        return right;

    Node *last = left;
    while(last->next != nullptr)
        last = last->next;
    last->next = right;
    return left;
}

struct Iterator
{
    Node *node;

    Iterator &operator++(   ) {                  node = node->next; return *this;}
    Iterator  operator++(int) {Node *tmp = node; node = node->next; return {tmp};}

    bool operator!=(Iterator const &other) const {return node != other.node;}
    bool operator==(Iterator const &other) const {return node == other.node;}

    int &operator* () const {return  node->value;}
    int *operator->() const {return &node->value;}
};

inline Iterator begin(List const list) {return {   list};}
inline Iterator   end(List           ) {return {nullptr};}

} // namespace list

using List = list::List;
