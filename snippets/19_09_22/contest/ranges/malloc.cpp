#include <cstdlib>
IntRange createIntRange(std::size_t const N)
{
    void * const memory = std::malloc(N * sizeof(int));
    return
    {
        .begin = static_cast<int *>(memory),
        .end   = static_cast<int *>(memory) + N,
    };
}
void deleteIntRange(IntRange const range)
{
    std::free(range.begin);
}
