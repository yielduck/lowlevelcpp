inline int *max_element(IntRange const range)
{
    auto max = range.begin;
    for(auto it = range.begin + 1; it < range.end; ++it)
        if(*max < *it)
            max = it;
    return max;
}
inline int const *max_element(IntConstRange const range)
{
    auto max = range.begin;
    for(auto it = range.begin + 1; it < range.end; ++it)
        if(*max < *it)
            max = it;
    return max;
}
