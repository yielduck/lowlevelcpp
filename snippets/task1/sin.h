#pragma once
#include "mod.h"
namespace my
{

double sin(double x)
{
    double const pi = 3.141592653589793;
    x = my::mod(x, 2. * pi);

    double summand = x;
    double sum = 0.;
    for(int i = 1; ; ++i)
    {
        if(sum + summand == sum)
            break;

        sum += summand;
        summand *= -x * x / (2 * i) / (2 * i + 1);
    }
    return sum;
}

} // namespace my
