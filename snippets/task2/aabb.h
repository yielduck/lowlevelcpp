#pragma once
#include "common/ray.h"

struct AABB // axis-aligned bounding box
{
    vec3 min, max;
};

inline MaybeTwoIntersections rayAABBIntersection(Ray const &ray, AABB const &aabb)
{
    vec3 const a = (aabb.min - ray.origin) / ray.direction;
    vec3 const b = (aabb.max - ray.origin) / ray.direction;
    vec3 const tMin =
    {
        a.x < b.x ? a.x : b.x,
        a.y < b.y ? a.y : b.y,
        a.z < b.z ? a.z : b.z,
    };
    vec3 const tMax =
    {
        a.x < b.x ? b.x : a.x,
        a.y < b.y ? b.y : a.y,
        a.z < b.z ? b.z : a.z,
    };
    auto const min = [](float const x, float const y) {return x < y ? x : y;};
    auto const max = [](float const x, float const y) {return x < y ? y : x;};
    return
    {
        max(max(tMin.x, tMin.y), tMin.z),
        min(min(tMax.x, tMax.y), tMax.z),
    };
}
