void iter_swap(ListIterator const a, ListIterator const b)
{
    int const tmp = *a;
    *a = *b;
    *b = tmp;
}
