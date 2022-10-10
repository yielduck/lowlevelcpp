#pragma once
#include "common/ray.h"
#include "common/maybe_two_intersections.h"

struct AABB // axis-aligned bounding box
{
    vec3 min, max;
};

inline MaybeTwoIntersections rayAABBIntersection(Ray const &ray, AABB const &aabb)
{
    vec3 const a = (aabb.min - ray.origin) / ray.direction;
    vec3 const b = (aabb.max - ray.origin) / ray.direction;
    auto const min = [](float const x, float const y) {return x < y ? x : y;};
    auto const max = [](float const x, float const y) {return x < y ? y : x;};
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
