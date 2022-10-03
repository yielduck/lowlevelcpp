char *itoa(std::int64_t const number)
{
    char * const s = static_cast<char *>(std::malloc(24));
    std::size_t i = 0;
    
    {
        std::int64_t num = number;
        do
        {
            s[i++] = '0' + std::abs(num % 10);
            num /= 10;
        } while(num != 0);
    }
    
    if(number < 0)
        s[i++] = '-';

    for(std::size_t j = 0; j < i - j - 1; ++j)
    {
        char const c = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = c;
    }
        
    s[i] = '\0';
    return s;
}
