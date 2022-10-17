#include "swap.h"
#include "max_element.h"
inline void selection_sort(IntRange const range)
{
    for(auto it = range.begin; it + 1 < range.end; ++it)
        swap(it, max_element(IntRange{it, range.end}));
}
