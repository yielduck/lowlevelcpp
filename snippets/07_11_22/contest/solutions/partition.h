#include "../bits/prepend.h"
#include "../bits/uncons.h"
ListPair partition(List list, auto const pred)
{
    ListPair pair = {nullptr, nullptr};
    while(list != nullptr)
    {
        ListUncons const u = uncons(list);
        if(pred(u.head->value))
            pair. first = prepend(u.head, pair. first);
        else
            pair.second = prepend(u.head, pair.second);
        list = u.tail;
    }
    return pair;
}
