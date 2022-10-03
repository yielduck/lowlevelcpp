#pragma once
#include "floor.h"
namespace my
{

double mod(double x, double y)
{
    return x - y * static_cast<double>(my::floor(x / y));
}

} // namespace my
