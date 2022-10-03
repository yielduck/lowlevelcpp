int accumulate(IntConstRange const range)
{
    int result = 0;
    for(int const *it = range.begin; it < range.end; ++it)
        result += *it;
    return result;
}
