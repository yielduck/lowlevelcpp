void fill(Matrix const mat)
{
    for(std::size_t i = 0; i < mat.height; ++i)
    for(std::size_t j = 0; j < mat.width; ++j)
        mat.data[i * mat.width + j] = i + j;
}
