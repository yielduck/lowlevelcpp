#include <cstdint>

using u64 = std::uint64_t;
u64 popcount(u64 const n)
{
    return n == 0
        ? 0
        : (n & 0x1) + popcount(n >> 1);
}
