#pragma once
#include "sphere.h"

#include <algorithm>
#include <optional>
#include <vector>

struct Hit
{
    vec3 position;
    vec3 normal;
    vec3 albedo;
};

std::optional<Hit> closestHit(Ray const &ray, std::vector<Sphere> const &sphere)
{
    if(sphere.size() == 0u)
        return std::nullopt;

    std::vector<RaySphereIntersection> intersection;
    for(auto const &s : sphere)
        intersection.push_back(raySphereIntersection(ray, s));

    auto const it = std::min_element(intersection.begin(), intersection.end());
    if(false == happened(*it))
        return std::nullopt;

    float const t = it->tMin;
    auto const i = it - intersection.begin();

    return Hit
    {
        .position = ray.point(t),
        .normal = normalize(ray.point(t) - sphere[i].origin),
        .albedo = sphere[i].albedo,
    };
}
