inline int const *find(IntConstRange const range, int const n)
{
    for(auto it = range.begin; it != range.end; ++it)
        if(*it == n)
            return it;
    return range.end;
}
