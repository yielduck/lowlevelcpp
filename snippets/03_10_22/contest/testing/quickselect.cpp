#include "int_range.h"

namespace student
{
#include "../sort/quickselect.h"
}

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
int main()
{
    auto const N = 2000000u;
    std::vector<int> v(N);
    
    std::mt19937 gen;
    std::uniform_int_distribution<int> distr(0, 1 << 16);
    for(auto i = 0u; i < N; ++i)
        v[i] = distr(gen);

    auto copy = v;    
    IntRange const range =
    {
        .begin = &v[0],
        .end   = &v[0] + N,
    };
    
    int n;
    std::cin >> n;
    student::quickselect(range, range.begin + n);
    std::nth_element(copy.begin(), copy.begin() + n, copy.end());
    bool good = v[n] == copy[n];
    for(int i = 0; i < n; ++i)
        good &= v[i] <= v[n];
    for(int i = n; i < N; ++i)
        good &= v[n] <= v[i];
    std::cout << good << std::endl;
}
