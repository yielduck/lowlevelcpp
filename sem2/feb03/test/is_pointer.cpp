namespace student
{
#include "../solution/is_pointer.h"
}

struct Test {};

#include <iostream>
int main() 
{
    std::cout << std::boolalpha;
    std::cout << "is_pointer<Test             >::value == " << student::is_pointer<Test>::value << std::endl
              << "is_pointer<Test const *     >::value == " << student::is_pointer<Test const *>::value << std::endl
              << "is_pointer<int              >::value == " << student::is_pointer<int>::value << std::endl
              << "is_pointer<int *            >::value == " << student::is_pointer<int *>::value << std::endl
              << "is_pointer<int const        >::value == " << student::is_pointer<int const>::value << std::endl
              << "is_pointer<int const *      >::value == " << student::is_pointer<int const *>::value << std::endl
              << "is_pointer<int const * const>::value == " << student::is_pointer<int const * const>::value << std::endl;
}
