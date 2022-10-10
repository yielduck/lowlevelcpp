void swap(int * const pa, int * const pb)
{
    int a = *pa;
    *pa = *pb;
    *pb = a;
}
void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

#include <iostream>
int main()
{
    int a = 5;
    int b = 1;
    swap(&a, &b);
    swap(a, b);
    std::cout << a << " " << b << std::endl;
}
