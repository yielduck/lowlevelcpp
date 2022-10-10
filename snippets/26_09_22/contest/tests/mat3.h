#include <cstddef>
#include <cstdint>
#include <cstdlib>
struct vec3
{
    float x, y, z;
};

struct mat3
{
    vec3 x, y, z;
    float       *operator[](std::ptrdiff_t const i) noexcept
    {
        return reinterpret_cast<float *>(&x + i);
    }
    float const *operator[](std::ptrdiff_t const i) const noexcept
    {
        return reinterpret_cast<float const *>(&x + i);
    }

};
