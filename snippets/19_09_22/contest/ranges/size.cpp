#include <cstddef>
std::ptrdiff_t size(IntRange const range)
{
    return range.end - range.begin;
}
