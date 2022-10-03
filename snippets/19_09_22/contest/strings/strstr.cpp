std::size_t strlen(char const * const str)
{
    std::size_t i = 0u;
    while(str[i] != '\0')
        ++i;
    return i;
}
int strncmp(char const * const s1, char const * const s2, std::size_t const n)
{
    for(std::size_t i = 0; i < n; ++i)
        if(s1[i] != s2[i])
            return s1[i] < s2[i] ? -1 : 1;
    return 0;
}
char const *strstr(char const * const haystack, char const * const needle)
{
    std::size_t const h = strlen(haystack);
    std::size_t const n = strlen(needle);
    for(std::size_t i = 0; i + n <= h; ++i)
        if(strncmp(haystack + i, needle, n) == 0)
            return haystack + i;
    return nullptr;
}
