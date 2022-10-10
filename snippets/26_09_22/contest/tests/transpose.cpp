#include "mat3.h"

namespace student
{
#include "../mat3/transpose.h"
}

#include <iostream>
int main()
{
    mat3 m;
    for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j)
        std::cin >> m[i][j];
    m = student::transpose(m);
    for(int i = 0; i < 3; ++i)
    {
        for(int j = 0; j < 3; ++j)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
}
