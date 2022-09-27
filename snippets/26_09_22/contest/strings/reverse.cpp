std::size_t strlen(char const * const s)
{
    std::size_t n = 0;
    while(s[n] != '\0')
        ++n;
    return n;
}
void reverse(char * const s)
{
    std::size_t const n = strlen(s);
    for(std::size_t i = 0; i + 1 < n - i; ++i)
    {
        char const c = s[i];
        s[i] = s[n - i - 1];
        s[n - i - 1] = c;
    }
}
