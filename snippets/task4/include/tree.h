#pragma once
#include "aabb.h"

#include <cassert>

#include <algorithm>
#include <numeric>
#include <ranges>
#include <span>
#include <variant>
#include <optional>

struct Node
{
    struct Children
    {
        Node *left, *right;
    };

    AABB box;
    std::variant<Children, Triangle> data;
};
using Tree = Node *;
inline Tree cons(Tree const left, AABB const &box, Tree const right) noexcept
{
    return new Node
    {
        .box = box,
        .data = Node::Children{left, right},
    };
}
inline Tree cons(Triangle const &triangle) noexcept
{
    return new Node
    {
        .box = toBox(triangle),
        .data = triangle,
    };
}
inline void destroyTree(Tree const tree) noexcept
{
    if(std::holds_alternative<Node::Children>(tree->data))
    {
        auto const [left, right] = std::get<Node::Children>(tree->data);
        destroyTree( left);
        destroyTree(right);
    }
    delete tree;
}

inline Tree createTree(std::span<Triangle> const triangle) noexcept
{
    assert(triangle.size() != 0);
    if(triangle.size() == 1)
        return cons(triangle[0]);

    auto const box = triangle | std::views::transform(toBox);
    AABB const bigBox = std::accumulate(box.begin() + 1, box.end(), box[0]);

    vec3 const diagonal = bigBox.max - bigBox.min;
    auto const proj =
    [
        i = diagonal.x > diagonal.y
            ? (diagonal.x > diagonal.z ? 0u : 2u)
            : (diagonal.y > diagonal.z ? 1u : 2u)
    ](Triangle const &t) noexcept
    {
        auto const &[r0, r1, r2] = t.r;
        return r0[i] + r1[i] + r2[i];
    };

    auto const mid = triangle.begin() + triangle.size() / 2;
    std::ranges::nth_element(triangle, mid, {}, proj);
    return cons
    (
        createTree({triangle.begin(), mid}),
        bigBox,
        createTree({mid,   triangle.end()})
    );
}

struct RayTreeIntersection
{
    Triangle triangle;
    RayTriangleIntersection intersection;
};
inline std::optional<RayTreeIntersection> rayTreeIntersection(Ray const &ray, Tree const tree) noexcept
{
    if(std::holds_alternative<Triangle>(tree->data))
    {
        auto const &triangle = std::get<Triangle>(tree->data);
        auto const intersection = rayTriangleIntersection(ray, triangle);
        return happened(intersection)
            ? std::optional<RayTreeIntersection>({.triangle = triangle, .intersection = intersection})
            : std::nullopt;
    }
    auto const [left, right] = std::get<Node::Children>(tree->data);
    auto const iLeft  = rayAABBIntersection(ray,  left->box);
    auto const iRight = rayAABBIntersection(ray, right->box);

    if(!happened(iLeft) && !happened(iRight))
        return std::nullopt;
    if(!happened(iLeft))
        return rayTreeIntersection(ray, right);
    if(!happened(iRight))
        return rayTreeIntersection(ray,  left);

    bool const lr = iLeft.tMin < iRight.tMin;
    auto const    tMid = lr ? iRight.tMin : iLeft.tMin;
    auto const  closer = lr ? left  : right;
    auto const further = lr ? right :  left;

    auto const iC = rayTreeIntersection(ray,  closer);
    auto const iF = rayTreeIntersection(ray, further);
    if(!iC)
        return iF;
    if(iC->intersection.t < tMid)
        return iC;
    if(!iF)
        return iC;
    return iC->intersection.t < iF->intersection.t ? iC : iF;
}
