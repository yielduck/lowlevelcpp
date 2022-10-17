#include <cstddef>
#include <cstdint>
#include <cstdlib>

using F = double(double);
struct Segment
{
    double begin, end;
};
namespace student
{
#include "../search/find_root.h"
}

#include <cmath>
double f0(double x) {return std::sin(x);}
double f1(double x) {return x * x - x - 1.;}
double f2(double x) {return std::log(x) - 1;}

#include <iostream>
int main()
{
    F const *f[] = {f0, f1, f2};
    Segment const s[] =
    {
        {2., 4.},
        {1., 2.},
        {1., 4.},
    };
    int n;
    std::cin >> n;
    std::cout << student::findRoot(s[n], f[n]) << std::endl;
}
