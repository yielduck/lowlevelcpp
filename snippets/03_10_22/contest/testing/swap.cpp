#include <cstddef>
#include <cstdint>
#include <cstdlib>

namespace student
{
#include "../elementary/swap.h"
}

#include <iostream>
int main()
{
    int a = 0;
    int b = 202;
    student::swap(&a, &b);
    std::cout << a << b;
    student::swap(&a, &a);
    std::cout << a << std::endl;
}
