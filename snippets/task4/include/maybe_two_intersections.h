#pragma once
struct MaybeTwoIntersections
{
    float tMin, tMax;
};
MaybeTwoIntersections const None = {.tMin = 0.f, .tMax = -1.f};
inline bool happened(MaybeTwoIntersections const i)
{
    return i.tMin <= i.tMax;
}
