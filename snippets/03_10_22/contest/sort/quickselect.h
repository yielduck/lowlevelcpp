#include "partition.h"
inline void quickselect(IntRange const range, int * const p)
{
    if(range.end - range.begin < 2)
        return;
    int const y = *range.begin;
    int * const mid1 = partition(range,             [y](int x){return x <  y;});
    int * const mid2 = partition({mid1, range.end}, [y](int x){return x == y;});
    if(p < mid1)
        quickselect({range.begin, mid1}, p);
    else if(mid2 <= p)
        quickselect({mid2,   range.end}, p);
}
