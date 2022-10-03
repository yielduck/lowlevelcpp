#pragma once
namespace my
{

double sqrt(double const a)
{
    double x = 1.;
    while(true)
    {
        double const dx = -0.5 * (x - a / x);
        if(x + dx == x)
            break;

        x += dx;
    }
    return x;
}

/* same thing but recursively
double sqrt_impl(double const a, double const x)
{
    double const dx = -0.5 * (x - a / x);
    return x == x + dx
        ? x
        : sqrt_impl(a, x + dx);
}
double sqrt(double const a)
{
    return sqrt_impl(a, 1.);
}
*/

} // namespace my
