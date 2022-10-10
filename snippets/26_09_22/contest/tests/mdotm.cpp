#include "mat3.h"
namespace student
{
#include "../mat3/mdotm.h"
}
using student::operator*;
#include <iostream>
int main()
{
    mat3 M[2];
    for(int k = 0; k < 2; ++k)
    for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
        std::cin >> M[k][i][j];
    mat3 const m = M[0] * M[1];
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
}
