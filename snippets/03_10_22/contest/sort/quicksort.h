#include "partition.h"
inline void quicksort(IntRange const range)
{
    if(range.end - range.begin < 2)
        return;
    int const y = *range.begin;
    int * const mid1 = partition(range,             [y](int x) {return x <  y;});
    int * const mid2 = partition({mid1, range.end}, [y](int x) {return x == y;});
    quicksort({range.begin, mid1});
    quicksort({mid2,   range.end});
}
