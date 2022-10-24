#include "siftdown.h"
inline void make_heap(IntRange const range)
{
    for(int i = (range.end - range.begin) / 2; i >= 0; --i)
        siftdown(range, i);
}
