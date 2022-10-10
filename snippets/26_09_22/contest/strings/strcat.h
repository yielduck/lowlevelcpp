std::size_t strlen(char const * const s)
{
    std::size_t n = 0;
    while(s[n] != '\0')
        ++n;
    return n;
}
char *strcat(char const * const s1, char const * const s2)
{
    std::size_t const n1 = strlen(s1);
    std::size_t const n2 = strlen(s2);
    char * const s = static_cast<char *>(std::malloc(n1 + n2 + 1));
    for(std::size_t i = 0; i <  n1; ++i)
        s[i] = s1[i];
    for(std::size_t i = 0; i <= n2; ++i)
        s[n1 + i] = s2[i];
    return s;
}
