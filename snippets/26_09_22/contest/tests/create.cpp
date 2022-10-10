#include "matrix.h"
namespace student
{
#include "../matrix/create.h"
}

#include <iostream>
int main()
{
    std::size_t n, m;
    std::cin >> n >> m;
    Matrix const mat = student::createMatrix(n, m);
    for(std::size_t i = 0; i < n * m; ++i)
        mat.data[i] = 0;
    std::cout << (mat.width == n);
    std::cout << (mat.height == m);
    std::cout << std::endl;
    student::deleteMatrix(mat);
}
