template<typename I>
void iter_swap(I a, I b)
{
    auto copy = *a;
    *a = *b;
    *b = copy;
}

template<typename RandomIt, typename Compare>
void sort(RandomIt begin, RandomIt end, Compare cmp)
{
    for(RandomIt i = begin; i + 1 < end; ++i)
    for(RandomIt j = i + 1; j     < end; ++j)
        if(!cmp(*i, *j))
            iter_swap(i, j);
}
