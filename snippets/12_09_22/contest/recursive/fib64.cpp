#include <cstdint>

using u64 = std::uint64_t;
u64 fib64_impl(u64 const n0, u64 const n1, u64 const left)
{
    return left == 0
        ? n0
        : fib64_impl(n1, n0 + n1, left - 1);
}
u64 fib64(u64 const n)
{
    return fib64_impl(0, 1, n);
}
