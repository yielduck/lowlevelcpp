#include <iostream>
#include <iomanip>

void toLower(char *s)
{
    while(*s != '\0')
    {
        if(*s >= 'A' && *s <= 'Z')
            *s += 'a' - 'A';
        ++s;
    }
}

int main()
{
    char s[6] = "tEsT";
    toLower(s);
    std::cout << s << std::endl;
}
