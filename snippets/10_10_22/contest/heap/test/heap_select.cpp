#include "int_range.h"

namespace student
{
#include "../heap_select.h"
}

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
int main()
{
    unsigned int const N = 500000u;
    std::vector<int> v(N);
    
    int test;
    std::cin >> test;
    if(test == 0)
    {
        for(auto i = 0u; i < N; ++i)
            v[i] = i;
    }
    else if(test == 1)
    {
        for(auto i = 0u; i < N; ++i)
            v[i] = N - i - 1u;
    }
    else if(test == 2)
    {
        for(auto i = 0u; i < N; ++i)
            v[i] = i;
        for(auto i = 0u; i < N; ++i)
            std::swap(v[i], v[i / 2]);
    }
    else
    {
        std::mt19937 gen(test);
        std::uniform_int_distribution<int> distr(0, 1 << test);
        for(auto i = 0u; i < N; ++i)
            v[i] = distr(gen);
    }

    auto copy = v;    
    IntRange const range =
    {
        .begin = &v[0],
        .end   = &v[0] + N,
    };
    
    unsigned int n;
    std::cin >> n;
    student::heap_select(range, range.begin + n);
    std::nth_element(copy.begin(), copy.begin() + n, copy.end());
    bool good = v[n] == copy[n];
    for(unsigned int i = 0; i < n; ++i)
        good &= v[i] <= v[n];
    for(unsigned int i = n; i < N; ++i)
        good &= v[n] <= v[i];
    std::cout << good << std::endl;
}
