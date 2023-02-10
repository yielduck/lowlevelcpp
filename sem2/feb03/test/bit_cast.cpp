namespace student
{
#include "../solution/bit_cast.h"
}

#include <iostream>
int main()
{
    std::cout << std::hex;
    std::cout << "0x" << student::bit_cast<unsigned int>(1.f) << std::endl;
    std::cout << student::bit_cast<float>(0x40000000) << std::endl;
}
