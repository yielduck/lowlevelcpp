std::size_t strlen(char const * const str)
{
    std::size_t i = 0u;
    while(str[i] != '\0')
        ++i;
    return i;
}
