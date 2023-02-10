namespace student
{
#include "../solution/sort.h"
}

#include <vector>
#include <iostream>
int main()
{
    std::vector<double> v;
    
    double x;
    while(std::cin >> x)
        v.push_back(x);
    
    student::sort(v.begin(), v.end(), std::less<double>{});
    
    for(double const a : v)
        std::cout << a << ' ';
    std::cout << std::endl;
}
