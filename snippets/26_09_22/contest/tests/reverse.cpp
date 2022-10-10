#include <cstddef>
#include <cstdint>
#include <cstdlib>

namespace student
{
#include "../strings/reverse.h"
}

#include <cstring>
#include <iostream>
int main()
{
    char s[1024] = {};
    std::cin >> s;
    student::reverse(s);
    std::cout << s << std::endl;
}
