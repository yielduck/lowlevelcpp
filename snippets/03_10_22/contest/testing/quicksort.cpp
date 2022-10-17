#include "int_range.h"

namespace student
{
#include "../sort/quicksort.h"
}

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
int main()
{
    auto const N = 500000u;
    std::vector<int> v(N);
    
    int seed;
    std::cin >> seed;
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> distr(0, 1 << 16);
    for(auto i = 0u; i < N; ++i)
        v[i] = distr(gen);

    IntRange const range =
    {
        .begin = &v[0],
        .end   = &v[0] + N,
    };
    student::quicksort(range);
    std::cout << std::is_sorted(range.begin, range.end) << std::endl;
}
