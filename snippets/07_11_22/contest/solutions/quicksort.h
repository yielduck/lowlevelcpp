#include "concatList.h"
#include "partition.h"
List quicksort(List list, auto const &cmp)
{
    if(list == nullptr)
        return list;
    ListUncons const u = uncons(list);
    auto const pred = [&cmp, x = u.head->value](int y) {return cmp(y, x);};
    ListPair const pair = partition(u.tail, pred);
    return concatList
    (
        quicksort(pair.first, cmp),
        prepend(u.head, quicksort(pair.second, cmp))
    );
}
