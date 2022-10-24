#include "int_range.h"
namespace student
{
#include "../make_heap.h"
}

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
int main()
{
    auto const N = 3000000u;
    std::vector<int> v(N);
    
    int seed;
    std::cin >> seed;
    std::mt19937 gen(seed);
    std::uniform_int_distribution<int> distr(0, 1 << 20);
    for(auto i = 0u; i < N; ++i)
        v[i] = distr(gen);

    IntRange const range =
    {
        .begin = &v[0],
        .end   = &v[0] + N,
    };
    student::make_heap(range);
    std::cout << std::is_heap(range.begin, range.end) << std::endl;
}
