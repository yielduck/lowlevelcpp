#include "make_heap.h"
inline void heap_sort(IntRange range)
{
    make_heap(range);
    while(range.begin < range.end--)
    {
        swap(range.begin, range.end);
        siftdown(range, 0);
    }
}
