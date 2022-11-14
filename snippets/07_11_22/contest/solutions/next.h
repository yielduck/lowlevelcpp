ListIterator next(ListIterator it, int const n = 1)
{
    for(int i = 0; i < n; ++i)
        ++it;
    return it;
}
