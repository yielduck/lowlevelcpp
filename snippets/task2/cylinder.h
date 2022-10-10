#pragma once
#include "common/ray.h"

struct Cylinder
{
    vec3 r0, r1;
    float radius;
};

inline MaybeTwoIntersections rayCylinderIntersection(Ray const &ray, Cylinder const &cylinder)
{
    vec3 const e = ray.origin - cylinder.r0;
    vec3 const l = normalize(cylinder.r1 - cylinder.r0);

    float const dl = dot(ray.direction, l);
    float const el = dot(e, l);
    float const l2 = dot(l, l);

    float const a = 1.f - dl * dl;
    float const b = dot(ray.direction, e) - dl * el;
    float const c = dot(e, e) - cylinder.radius * cylinder.radius - el * el;
    float const det = b * b - a * c;
    if(det < 0.f)
        return None;

    float const t[] =
    {
        (-b - sqrt(det)) / a,
        (-b + sqrt(det)) / a,
        dot(cylinder.r0 - ray.origin, l) / dl,
        dot(cylinder.r1 - ray.origin, l) / dl,
    };
    auto const min = [](float const x, float const y) {return x < y ? x : y;};
    auto const max = [](float const x, float const y) {return x < y ? y : x;};
    return
    {
        max(min(t[0], t[1]), min(t[2], t[3])),
        min(max(t[0], t[1]), max(t[2], t[3])),
    };
}
