#include "../uncons.h"
#include "../prepend.h"
List mergeList(List const left, List const right)
{
    if(left == nullptr)
        return right;
    if(right == nullptr)
        return left;
    ListUncons const l = uncons(left);
    ListUncons const r = uncons(right);
    return l.head->value < r.head->value
        ? prepend(l.head, mergeList(l.tail, right))
        : prepend(r.head, mergeList(left,  r.tail));
}
