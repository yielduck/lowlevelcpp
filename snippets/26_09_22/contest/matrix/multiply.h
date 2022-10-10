#include "create.h"
Matrix operator*(Matrix const m1, Matrix const m2)
{
    Matrix const m = createMatrix(m2.width, m1.height);
    for(std::size_t i = 0; i < m.height; ++i)
    for(std::size_t j = 0; j < m.width; ++j)
    {
        m.data[i * m.width + j] = 0.f;
        for(std::size_t k = 0; k < m1.width; ++k)
            m.data[i * m.width + j] += m1.data[i * m1.width + k]
                                     * m2.data[k * m2.width + j];
    }
    return m;
}
