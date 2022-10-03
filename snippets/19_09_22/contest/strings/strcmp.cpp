int strcmp(char const * const s1, char const * const s2)
{
    std::size_t i = 0;
    for(; s1[i] == s2[i]; ++i)
        if(s1[i] == '\0')
            return 0;
    return s1[i] < s2[i] ? -1 : 1;
}
