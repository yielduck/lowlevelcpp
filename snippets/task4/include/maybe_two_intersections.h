#pragma once
struct MaybeTwoIntersections
{
    float tMin, tMax;
};
MaybeTwoIntersections const None = {.tMin = 0.f, .tMax = -1.f};
inline bool happened(MaybeTwoIntersections const i)
{
    return i.tMax > 0.f && i.tMin <= i.tMax;
}
