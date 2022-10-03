std::int64_t atoi_impl(char const * const s, std::int64_t const a)
{
    std::int64_t const i = s[0] - '0';
    return i >= 0 && i <= 9
        ? atoi_impl(s + 1, 10 * a + i)
        : a;
}
std::int64_t atoi(char const * const s)
{
    return s[0] == '-'
        ? -atoi_impl(s + 1, 0)
        :  atoi_impl(s    , 0);
}
