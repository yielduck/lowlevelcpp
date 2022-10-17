#include "int_range.h"
namespace student
{
#include "../search/lower_bound.h"
}

#include <vector>
#include <cstdio>
#include <iostream>
#include <chrono>
int main()
{
    int n;
    std::scanf("%d\n", &n);
    
    std::vector<int> v;
    
    int x0, x1, xn;
    if(3 == std::scanf("[%d,%d..%d]", &x0, &x1, &xn))
    {
        int const dx = x1 - x0;
        v.reserve((xn - x0) / dx);
        for(int x = x0; x <= xn; x += dx)
            v.push_back(x);
    }
    else
    {
        while(std::cin >> xn)
            v.push_back(xn);
    }

    IntConstRange const range =
    {
        .begin = &v[0],
        .end   = &v[0] + v.size(),
    };
    auto const t0 = std::chrono::steady_clock::now();
    int const * const p = student::lower_bound(range, n);
    auto const t1 = std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> const dt = t1 - t0;
    if(dt.count() > 10.)
    {
        std::cout << "timeout: " << dt.count() << "ms" << std::endl;
        return 0;
    }
    if(p == range.end)
        std::cout << "not found" << std::endl;
    else
        std::cout << "a[" << p - range.begin << "] = " << *p << std::endl;
}
