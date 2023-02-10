using u8  = std::uint8_t;
using u64 = std::uint64_t;

template<u64 a0, u64 a1, u64 n>
struct Fib64
{
    static constexpr u64 value = Fib64<a0, a1, n - 1>::value
                               + Fib64<a0, a1, n - 2>::value;
};
template<u64 a0, u64 a1>
struct Fib64<a0, a1, 0>
{
    static constexpr u64 value = a0;
};
template<u64 a0, u64 a1>
struct Fib64<a0, a1, 1>
{
    static constexpr u64 value = a1;
};

template<u64 a0, u64 a1, u64... xs>
u64 fib64_impl(u8 const i, std::integer_sequence<u64, xs...>)
{
    constexpr u64 array[] = {Fib64<a0, a1, xs>::value...};
    return array[i];
}
template<u64 a0, u64 a1>
u64 fib64(u8 const i)
{
    return fib64_impl<a0, a1>(i, std::make_integer_sequence<u64, 256>{});
}
