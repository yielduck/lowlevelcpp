#include "mat3.h"
namespace student
{
#include "../mat3/mdotv.h"
}
using student::operator*;
#include <iostream>
int main()
{
    mat3 m;
    for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
        std::cin >> m[i][j];
    vec3 v;
    std::cin >> v.x >> v.y >> v.z;
    vec3 const a = m * v;
    std::cout << a.x << " " << a.y << " " << a.z << std::endl;
}
