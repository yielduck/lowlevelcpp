#pragma once
#include "tree.h"
namespace list
{

struct ListNode
{
    Tree value;
    ListNode *next;
};

using List = ListNode *;

inline List cons(Tree const value, List const next)
{
    ListNode * const node = static_cast<ListNode *>(std::malloc(sizeof(ListNode)));
    node->value = value;
    node->next = next;
    return node;
}
inline List prepend(ListNode * const head, List const tail)
{
    head->next = tail;
    return head;
}

struct ListUncons
{
    ListNode *head;
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
        auto const [x, xs] = uncons(list);
        std::free(x);
        destroy(xs);
    }
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
        auto const [x, xs] = uncons(list);
        accum = prepend(x, accum);
        list = xs;
    }
    return accum;
}
inline List concat(List const left, List const right)
{
    if(left == nullptr)
        return right;

    ListNode *last = left;
    while(last->next != nullptr)
        last = last->next;
    last->next = right;
    return left;
}

struct Iterator
{
    ListNode *node;

    Iterator &operator++(   ) {                      node = node->next; return *this;}
    Iterator  operator++(int) {ListNode *tmp = node; node = node->next; return {tmp};}

    bool operator!=(Iterator const &other) const {return node != other.node;}
    bool operator==(Iterator const &other) const {return node == other.node;}

    Tree &operator* () const {return  node->value;}
    Tree *operator->() const {return &node->value;}
};

inline Iterator begin(List const list) {return {   list};}
inline Iterator   end(List           ) {return {nullptr};}

} // namespace list

using List = list::List;
