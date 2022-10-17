#include "lower_bound.h"
inline int const *binary_search(IntConstRange const range, int const n)
{
    int const * const p = lower_bound(range, n);
    return p == range.end || *p != n
        ? range.end
        : p;
}
