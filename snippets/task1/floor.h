#pragma once
#include <cstdint>
namespace my
{

std::int64_t floor(double const x)
{
    double const fx = x >= 0. ? x : x - 1.;
    return static_cast<std::int64_t>(fx);
}

} // namespace my
