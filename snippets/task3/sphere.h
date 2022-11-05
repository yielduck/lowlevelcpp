#pragma once
#include <ray.h>

struct Sphere
{
    vec3 origin;
    float radius;

    vec3 albedo;
};

struct RaySphereIntersection
{
    float tMin, tMax;
};
bool happened(RaySphereIntersection const i)
{
    return i.tMin < i.tMax && i.tMin > 1e-5f;
}
bool operator<(RaySphereIntersection const left, RaySphereIntersection const right)
{
    if(!happened(left))
        return false;
    if(!happened(right))
        return true;
    return left.tMin < right.tMin;
}

inline RaySphereIntersection raySphereIntersection(Ray const &ray, Sphere const &sphere)
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
