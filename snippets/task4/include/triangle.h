#pragma once
#include "vec2.h"
#include "ray.h"

struct Triangle
{
    vec3 r[3];
    vec2 t[3];
    vec3 n[3];
};

struct RayTriangleIntersection
{
    float t, p, q;
};
inline bool happened(RayTriangleIntersection const &i)
{
    return i.t >= 1e-4f
        && i.p >= 0.f
        && i.q >= 0.f
        && i.p + i.q <= 1.f;
}
inline bool operator<(RayTriangleIntersection const &i1, RayTriangleIntersection const &i2)
{
    if(!happened(i1))
        return false;
    if(!happened(i2))
        return true;
    return i1.t < i2.t;
}
inline auto interpolate(auto const * const v, RayTriangleIntersection const &i)
{
    return v[0] * (1.f - i.p - i.q) + v[1] * i.p + v[2] * i.q;
}

// ray: r = o + d * t
// triangle: r - r0 = p * (r1 - r0) + q * (r2 - r0)
// substitute: o + d * t - r0 = p * (r1 - r0) + q * (r2 - r0)
// o - r0 = -d * t + p * (r1 - r0) + q * (r2 - r0)
// c = -d * t + p * a + q * b
// mat3(-d, a, b) * vec3(t, p, q) = c
inline RayTriangleIntersection rayTriangleIntersection(Ray const &ray, Triangle const &triangle)
{
    vec3 const a = triangle.r[1] - triangle.r[0];
    vec3 const b = triangle.r[2] - triangle.r[0];
    vec3 const c = ray.origin    - triangle.r[0];
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
