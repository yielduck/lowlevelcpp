#include <cstdint>

using u64 = std::uint64_t;
u64 gcd(u64 const x, u64 const y)
{
    return y == 0
        ? x
        : gcd(y, x % y);
}
