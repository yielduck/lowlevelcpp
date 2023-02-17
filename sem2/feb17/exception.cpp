#include <iostream>
int func(int i)
{
    if(i < 0)
        throw 1;
    else if (i == 0)
        throw "exception";
    return i;
}
int main()
{
    try
    {
        int i = func(0);
        return i;
    }
    catch(int i)
    {
        std::cout << i << std::endl;
    }
    catch(char const * const str)
    {
        std::cout << str << std::endl;
    }
}
