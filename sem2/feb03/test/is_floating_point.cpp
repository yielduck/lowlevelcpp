namespace student
{
#include "../solution/is_floating_point.h"
}

struct Test {};

#include <iostream>
int main() 
{
    std::cout << student::is_floating_point<       Test>::value
              << student::is_floating_point<        int>::value
              << student::is_floating_point<std::string>::value
              << student::is_floating_point<      float>::value
              << student::is_floating_point<     double>::value
              << student::is_floating_point<long double>::value
              << std::endl;
}
