#include <iostream>
#include <iomanip>
int main()
{
    float f = 1.5f;

    unsigned int *pi = reinterpret_cast<unsigned int *>(&f);

    std::cout << std::hex;
    std::cout << "0x" << *pi << std::endl;
}
