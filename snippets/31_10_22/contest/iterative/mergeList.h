#include "reverseList.h"
List concatList(List const left, List const right)
{
    if(left == nullptr)
        return right;
    Node *last = left;
    while(last->next != nullptr)
        last = last->next;
    last->next = right;
    return left;
}
List mergeList(List left, List right)
{
    List result = nullptr;
    while(true)
    {
        if(left  == nullptr)
            return concatList(reverseList(result), right);
        if(right == nullptr)
            return concatList(reverseList(result),  left);

        ListUncons const l = uncons(left);
        ListUncons const r = uncons(right);
        if(l.head->value < r.head->value)
        {
            result = prepend(l.head, result);
            left = l.tail;
        }
        else
        {
            result = prepend(r.head, result);
            right = r.tail;
        }
    }
}
