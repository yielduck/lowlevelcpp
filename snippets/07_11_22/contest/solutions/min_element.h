#include "next.h"
ListIterator min_element(ListIterator const first, ListIterator const last)
{
    if(first == last)
        return last;

    auto min = first;
    for(auto it = next(first); it != last; ++it)
        if(*it < *min)
            min = it;
    return min;
}
