#include "iter_swap.h"
#include "min_element.h"
void selection_sort(ListIterator const first, ListIterator const last)
{
    if(first == last)
        return;
    iter_swap(first, min_element(first, last));
    selection_sort(next(first), last);
}
