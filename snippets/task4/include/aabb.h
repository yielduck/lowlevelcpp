#pragma once
#include "triangle.h"
#include "maybe_two_intersections.h"

inline float min(float const x, float const y) noexcept {return x < y ? x : y;};
inline float max(float const x, float const y) noexcept {return x < y ? y : x;};

struct AABB // axis-aligned bounding box
{
    vec3 min, max;
};

inline AABB operator+(AABB const &a, AABB const &b) noexcept
{
    return
    {
        .min =
        {
            min(a.min.x, b.min.x),
            min(a.min.y, b.min.y),
            min(a.min.z, b.min.z),
        },
        .max =
        {
            max(a.max.x, b.max.x),
            max(a.max.y, b.max.y),
            max(a.max.z, b.max.z),
        },
    };
}

inline MaybeTwoIntersections rayAABBIntersection(Ray const &ray, AABB const &aabb) noexcept
{
    vec3 const a = (aabb.min - ray.origin) / ray.direction;
    vec3 const b = (aabb.max - ray.origin) / ray.direction;
    vec3 const tMin =
    {
        min(a.x, b.x),
        min(a.y, b.y),
        min(a.z, b.z),
    };
    vec3 const tMax =
    {
        max(a.x, b.x),
        max(a.y, b.y),
        max(a.z, b.z),
    };
    return
    {
        max(max(tMin.x, tMin.y), tMin.z),
        min(min(tMax.x, tMax.y), tMax.z),
    };
}
inline AABB toBox(Triangle const &t) noexcept
{
    auto const &[r0, r1, r2] = t.r;
    return
    {
        .min =
        {
            .x = min(r0.x, min(r1.x, r2.x)),
            .y = min(r0.y, min(r1.y, r2.y)),
            .z = min(r0.z, min(r1.z, r2.z)),
        },
        .max =
        {
            .x = max(r0.x, max(r1.x, r2.x)),
            .y = max(r0.y, max(r1.y, r2.y)),
            .z = max(r0.z, max(r1.z, r2.z)),
        },
    };
};
