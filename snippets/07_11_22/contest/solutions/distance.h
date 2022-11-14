#include "next.h"
int distance(ListIterator const first, ListIterator const last)
{
    return first == last
        ? 0
        : 1 + distance(next(first), last);
}
