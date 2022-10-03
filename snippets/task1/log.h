#pragma once
#include "sqrt.h"
#include <iostream>
namespace my
{

double log(double x)
{
    if(x > 1.)
        return -my::log(1. / x);

    double sum = 0.;
    double twomk = 0.5;
    double x2k = my::sqrt(x);

    while(true)
    {
        double const a = twomk * x2k / (1. + x2k);
        if(sum == sum + a)
            return 1. / (x / (x - 1.) - sum);

        sum += a;
        twomk *= 0.5;
        x2k = my::sqrt(x2k);
    }
}

} // namespace my
