#include "matrix.h"
namespace student
{
#include "../matrix/multiply.h"
}

#include "../matrix/create.h"

using student::operator*;

#include <iostream>
int main()
{
    Matrix m1 = createMatrix(4, 3);
    Matrix m2 = createMatrix(2, 4);
    
    for(std::size_t i = 0; i < m1.height; ++i)
    for(std::size_t j = 0; j < m1.width; ++j)
        std::cin >> m1.data[i * m1.width + j];
        
    for(std::size_t i = 0; i < m2.height; ++i)
    for(std::size_t j = 0; j < m2.width; ++j)
        std::cin >> m2.data[i * m2.width + j];
    
    
    Matrix m = m1 * m2;
    
    for(std::size_t i = 0; i < m.height; ++i)
    {
        for(std::size_t j = 0; j < m.width; ++j)
            std::cout << m.data[i * m.width + j] << " ";
        std::cout << std::endl;
    }

    deleteMatrix(m1);
    deleteMatrix(m2);
    deleteMatrix(m );
}
