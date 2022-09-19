#include <cstdint>

using u64 = std::uint64_t;
u64 fib64(u64 const n)
{
    u64 n0 = 0;
    u64 n1 = 1;
    for(u64 i = 0; i < n; ++i)
    {
        u64 const sum = n0 + n1;
        n0 = n1;
        n1 = sum;
    }
    return n0;
}
