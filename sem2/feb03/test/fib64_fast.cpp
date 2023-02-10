#include <cstdint>
#include <utility>
namespace student
{
#include "../solution/fib64_fast.h"
}

#include <iostream>
int main()
{
    using u64 = std::uint64_t;
    u64 const N = 400000;
    u64 sum1 = 0;
    for(u64 i = 0; i < N; ++i)
        sum1 += student::fib64<1, 3>(i % 256);
    u64 sum2 = 0;
    for(u64 i = 0; i < N; ++i)
        sum2 += student::fib64<2, 5>(i % 256);
    std::cout << sum1 << ' ' << sum2 << std::endl;
}
