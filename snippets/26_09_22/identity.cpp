#include <cstddef>
#include <cstdlib>

struct Matrix
{
    float *data;
    std::size_t width, height;
};

#include "contest/matrix/create.cpp"

#include <iostream>
int main()
{
    std::size_t n, m;
    std::cin >> n >> m;

    Matrix const mat = createMatrix(n, m);
    for(std::size_t i = 0; i < mat.height; ++i)
    for(std::size_t j = 0; j < mat.width ; ++j)
        mat.data[i * mat.width + j] = i == j ? 1.f : 0.f;

    for(std::size_t i = 0; i < mat.height; ++i)
    {
        for(std::size_t j = 0; j < mat.width; ++j)
            std::cout << mat.data[i * mat.width + j] << " ";
        std::cout << std::endl;
    }

    deleteMatrix(mat);
}
