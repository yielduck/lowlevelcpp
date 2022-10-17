inline int const *lower_bound(IntConstRange range, int const n)
{
    if(range.begin == range.end)
        return range.end;
    int const * const mid = range.begin + (range.end - range.begin) / 2;
    return *mid >= n
        ? lower_bound({range.begin,   mid}, n)
        : lower_bound({mid + 1, range.end}, n);
}
