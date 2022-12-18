#pragma once
struct MaybeTwoIntersections
{
    float tMin, tMax;
};
MaybeTwoIntersections const None = {.tMin = 0.f, .tMax = -1.f};
inline bool happened(MaybeTwoIntersections const i)
{
    return i.tMin > 1e-4f && i.tMin <= i.tMax;
}
