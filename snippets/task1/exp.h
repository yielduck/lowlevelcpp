#pragma once
#include "powi.h"
namespace my
{

double exp(double const x)
{
    int const ix = static_cast<int>(x + 0.5);
    double const fx = x - ix;
    double const e = 2.71828182845904523;
    double f = 0.;
    double df = 1.;
    for(int i = 1; ; ++i)
    {
        if(f + df == f)
            break;
        f += df;
        df *= fx / i;
    }
    return f * my::powi(e, ix);
}

} // namespace my
