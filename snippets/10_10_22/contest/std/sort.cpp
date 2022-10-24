#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v;
    int x;
    while(std::cin >> x)
        v.push_back(x);
    std::sort(v.begin(), v.end(), std::greater<int>{});
    for(int a : v)
        std::cout << a << " ";
    std::cout << std::endl;
}
