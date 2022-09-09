namespace my
{

double abs(double const x)
{
    return x >= 0. ? x : -x;
}

double sqrt(double const a)
{
    double x0 = 1.;
    while(true)
    {
        double const b = x0 * x0;
        double const diff = b - a;
        double const absdiff = my::abs(diff);
        if(b == 0 || absdiff / b < 1e-10)
            break;

        double const x1 = 0.5 * (x0 + a / x0);
        x0 = x1;
    }
    return x0;
}

} // namespace my

#include <iostream>
#include <iomanip>
#include <cmath>
int main()
{
    double const x = 2.;
    std::cout << std::setprecision(16);
    std::cout <<  my::sqrt(x) << std::endl;
    std::cout << std::sqrt(x) << std::endl;
}
