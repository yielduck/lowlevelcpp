#include "int_range.h"

namespace student
{
#include "../sort/partition.h"
}

#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v;
    int x;
    while(std::cin >> x)
        v.push_back(x);

    IntRange const range =
    {
        .begin = &v[0],
        .end   = &v[0] + v.size(),
    };
    auto const pred = [](int y) {return y < 0;};
    int const * const p = student::partition(range, pred);
    bool good = true;
    for(auto it = range.begin; it < p; ++it)
        good &= pred(*it);
    for(auto it = p; it < range.end; ++it)
        good &= !pred(*it);
    if(good)
    {
        if(p != range.end)
            std::cout << "partition point: i = " << p - range.begin << std::endl;
        else
            std::cout << "not found" << std::endl;
    }
    else
    {
        std::cout << "bad partition: i = " << p - range.begin << std::endl;
        for(int a : v)
            std::cout << a << " ";
        std::cout << std::endl;
    }
}
