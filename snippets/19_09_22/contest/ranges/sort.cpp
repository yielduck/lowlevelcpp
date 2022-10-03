void sort(IntRange const range)
{
    using i64 = std::int64_t;
    int * const a = range.begin;
    i64 const l = range.end - range.begin;
    for(i64 i =     0; i + 1 < l; ++i)
    for(i64 j = i + 1; j     < l; ++j)
        if(a[i] > a[j])
        {
            int const t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
}
