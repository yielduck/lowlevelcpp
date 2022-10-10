Matrix createMatrix(std::size_t const n, std::size_t const m)
{
    return
    {
        .data = static_cast<float *>(std::malloc(sizeof(float) * n * m)),
        .width = n,
        .height = m,
    };
}
void deleteMatrix(Matrix const m)
{
    std::free(m.data);
}
