#include "../elementary/swap.h"
inline int *partition(IntRange range, auto const pred)
{
    int *b = range.begin;
    int *e = range.end - 1;
    while(true)
    {
        while(b < range.  end &&  pred(*b))
            ++b;
        while(range.begin < e && !pred(*e))
            --e;
        if(b >= e)
            return b;
        swap(b++, e--);
    }
}
