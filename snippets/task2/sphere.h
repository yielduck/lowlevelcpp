#pragma once
#include "common/ray.h"

struct Sphere
{
    vec3 origin;
    float radius;
};

inline MaybeTwoIntersections raySphereIntersection(Ray const &ray, Sphere const &sphere)
{
    vec3 const l = ray.origin - sphere.origin;
    float const dl = dot(ray.direction, l);
    float const det = dl * dl - dot(l, l) + sphere.radius * sphere.radius;
    return
    {
        .tMin = -dl - std::sqrt(det),
        .tMax = -dl + std::sqrt(det),
    };
}
