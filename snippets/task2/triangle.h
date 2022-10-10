#pragma once
#include "common/ray.h"

struct Triangle
{
    vec3 r0, r1, r2;
};

struct RayTriangleIntersection
{
    float t, p, q;
};
inline bool happened(RayTriangleIntersection const &i)
{
    return i.p >= 0.f
        && i.q >= 0.f
        && i.p + i.q <= 1.f;
}

// ray: r = o + d * t
// triangle: r - r0 = p * (r1 - r0) + q * (r2 - r0)
// substitute: o + d * t - r0 = p * (r1 - r0) + q * (r2 - r0)
// o - r0 = -d * t + p * (r1 - r0) + q * (r2 - r0)
// c = -d * t + p * a + q * b
// mat3(-d, a, b) * vec3(t, p, q) = c
inline RayTriangleIntersection rayTriangleIntersection(Ray const &ray, Triangle const &triangle)
{
    vec3 const a = triangle.r1 - triangle.r0;
    vec3 const b = triangle.r2 - triangle.r0;
    vec3 const c = ray.origin - triangle.r0;
    vec3 const d = ray.direction;
    float const det0 = dot(-d, cross(a, b));
    float const det1 = dot( c, cross(a, b));
    float const det2 = dot(-d, cross(c, b));
    float const det3 = dot(-d, cross(a, c));
    return 
    {
        .t = det1 / det0,
        .p = det2 / det0,
        .q = det3 / det0,
    };
}
