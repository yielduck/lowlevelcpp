#include <cstdint>

namespace student
{
#include "../solution/fib64.h"
}

#include <utility>
#include <iostream>
template<std::size_t... I>
void print(std::index_sequence<I...>)
{
    ((std::cout << student::fib64<I>() << ' '),...);
    std::cout << std::endl;
}
int main()
{
    print(std::make_index_sequence<256>{});
}
