#pragma once
#include "vec2.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

struct Color
{
    unsigned char r, g, b;
};


vec3 toVec3(Color const c)
{
    return
    {
        c.r / 255.f,
        c.g / 255.f,
        c.b / 255.f,
    };
}

struct Image
{
    Color *color;
    int width, height;

    Color const *operator[](int const y) const {return color + (height - y - 1) * width;}
};

inline Image createImage(char const * const filename)
{
    int w, h, c;
    unsigned char * const bytes = stbi_load(filename, &w, &h, &c, 3);
    return
    {
        .color = reinterpret_cast<Color *>(bytes),
        .width = w,
        .height = h,
    };
}
inline void deleteImage(Image const &image)
{
    std::free(image.color);
}

inline vec3 sample(Image const &image, vec2 const &v)
{
    int const x = v.x * image.width;
    int const y = v.y * image.height;

    float const tx = v.x * image.width - x;
    float const ty = v.y * image.height - y;

    return toVec3(image[y    ][x    ]) * ((1.f - ty) * (1.f - tx))
         + toVec3(image[y    ][x + 1]) * ((1.f - ty) *        tx )
         + toVec3(image[y + 1][x    ]) * (       ty  * (1.f - tx))
         + toVec3(image[y + 1][x + 1]) * (       ty  *        tx );
}
