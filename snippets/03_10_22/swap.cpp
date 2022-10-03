#include <cstdlib>

void swap(auto *pa, auto *pb)
{
    auto a = *pa;
    *pa = *pb;
    *pb = a;
}

#include <iostream>
int main()
{
    double a = 1.;
    double b = 2.;
    swap(&a, &b);
    std::cout << a << " " << b << std::endl;
}
