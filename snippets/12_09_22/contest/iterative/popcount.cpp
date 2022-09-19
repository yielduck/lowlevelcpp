#include <cstdint>

using u64 = std::uint64_t;
u64 popcount(u64 n)
{
    u64 count = 0;
    while(n != 0)
    {
        count += n % 2;
        n /= 2;
    }
    return count;
}
