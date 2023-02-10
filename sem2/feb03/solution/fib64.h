template<std::uint64_t n>
std::uint64_t fib64() {return fib64<n - 1>() + fib64<n - 2>();}
template<>
std::uint64_t fib64<0>() {return 0;}
template<>
std::uint64_t fib64<1>() {return 1;}
