#include "int_range.h"
namespace student
{
#include "../elementary/max_element.h"
}

#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v;
    int x;
    while(std::cin >> x)
        v.push_back(x);

    IntConstRange const range =
    {
        .begin = &v[0],
        .end   = &v[0] + v.size(),
    };
    int const * const p = student::max_element(range);
    if(p == range.end)
        std::cout << "empty" << std::endl;
    else
        std::cout << "a[" << p - range.begin << "] = " << *p << std::endl;
}
