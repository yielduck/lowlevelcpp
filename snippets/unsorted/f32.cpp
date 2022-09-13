#include <cstdint>
using u32 = std::uint32_t;
struct BitFloat
{
    u32  mantissa : 23;
    u32  exponent :  8;
    bool sign     :  1;
};

inline BitFloat fromFloat(float const f) noexcept
{
    return *reinterpret_cast<BitFloat const *>(&f);
}
inline float toFloat(BitFloat const f) noexcept
{
    return *reinterpret_cast<float const *>(&f);
}

#include <iostream>
#include <iomanip>
#include <bitset>
int main()
{
    BitFloat const bf = fromFloat(1.5f);
    std::cout << std::hex;
    std::cout << (bf.sign ? "-" : "+") << std::endl;
    std::cout << std::bitset< 8>(bf.exponent) << " : " << bf.exponent << std::endl;
    std::cout << std::bitset<23>(bf.mantissa) << " : " << bf.mantissa << std::endl;

    std::cout << std::endl;
    float const f = toFloat
    ({
        .mantissa = 0x400000,
        .exponent = 0x7f,
        .sign = true,
    });
    std::cout << f << std::endl;
}
