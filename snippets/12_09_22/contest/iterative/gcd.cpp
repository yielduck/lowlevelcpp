#include <cstdint>

using u64 = std::uint64_t;
u64 gcd(u64 x, u64 y)
{
    while(y != 0)
    {
        u64 const remainder = x % y;
        x = y;
        y = remainder;
    }
    return x;
}
