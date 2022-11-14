ListIterator find(ListIterator const first, ListIterator const last, int const n)
{
    for(auto it = first; it != last; ++it)
        if(n == *it)
            return it;
    return last;
}
