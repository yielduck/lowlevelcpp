#include <iostream>

int main(int, char **, char *env[])
{
    while(*env != nullptr)
        std::cout << *(env++) << std::endl;
}
