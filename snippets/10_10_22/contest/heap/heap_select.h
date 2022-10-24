#include "make_heap.h"
inline void heap_select(IntRange const range, int * const p)
{
    IntRange const heap = {range.begin, p + 1};
    make_heap(heap);
    for(auto it = p + 1; it < range.end; ++it)
        if(*it < *range.begin)
        {
            swap(range.begin, it);
            siftdown(heap, 0);
        }
    if(range.begin < p)
        swap(range.begin, p);
}
