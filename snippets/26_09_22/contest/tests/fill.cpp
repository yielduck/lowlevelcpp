#include "matrix.h"
namespace student
{
#include "../matrix/fill.h"
}

#include <iostream>
int main()
{
    std::size_t n, m;
    std::cin >> n >> m;
    Matrix const mat =
    {
        .data = static_cast<float *>(std::malloc(sizeof(float) * n * m)),
        .width = n,
        .height = m,
    };
    student::fill(mat);
    for(std::size_t i = 0; i < mat.height; ++i)
    {
        for(std::size_t j = 0; j < mat.width; ++j)
            std::cout << mat.data[i * mat.width + j] << " ";
        std::cout << std::endl;
    }
    std::free(mat.data);
}
