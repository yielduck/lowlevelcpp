#include "log.h"
#include "exp.h"
#include "sin.h"
#include "tan.h"

#include <iostream>
#include <iomanip>
#include <cmath>
int main()
{
    double x;
    std::cin >> x;
    std::cout << std::setprecision(16);
    std::cout << "my : " << my ::sin(x) << std::endl;
    std::cout << "std: " << std::sin(x) << std::endl;
}
