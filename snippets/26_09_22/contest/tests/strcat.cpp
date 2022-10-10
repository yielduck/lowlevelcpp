#include <cstddef>
#include <cstdint>
#include <cstdlib>

namespace student
{
#include "../strings/strcat.h"
}

#include <iostream>
int main()
{
    std::string s1, s2;
    std::getline(std::cin, s1);
    std::getline(std::cin, s2);
    char * const s = student::strcat(s1.c_str(), s2.c_str());
    std::cout << s << std::endl;
    std::free(s);
}
