#pragma once
#include "mod.h"
namespace my
{

double tan(double x)
{
    int const N = 10; // todo: adapt to abs(x)
    double denom = 2 * N + 1;
    for(int i = N; i > 0; --i)
        denom = 2 * i - 1 - x * x / denom;
    return x / denom;
}

} // namespace my
