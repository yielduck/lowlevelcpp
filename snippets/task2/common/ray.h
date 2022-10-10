#pragma once
#include "vec3.h"
struct Ray
{
    vec3 origin;
    vec3 direction;

    vec3 point(float const t) const {return origin + direction * t;}
};

struct MaybeTwoIntersections
{
    float tMin, tMax;
};
MaybeTwoIntersections const None = {.tMin = 0.f, .tMax = -1.f};
inline bool happened(MaybeTwoIntersections const i)
{
    return i.tMin < i.tMax;
}
