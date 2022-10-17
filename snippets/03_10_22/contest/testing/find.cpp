#include "int_range.h"
namespace student
{
#include "../search/find.h"
}

#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v;
    int n, x;
    std::cin >> n;
    while(std::cin >> x)
        v.push_back(x);

    IntConstRange const range =
    {
        .begin = &v[0],
        .end   = &v[0] + v.size(),
    };
    int const * const p = student::find(range, n);
    if(p == range.end)
        std::cout << "not found" << std::endl;
    else
        std::cout << "a[" << p - range.begin << "] = " << *p << std::endl;
}
