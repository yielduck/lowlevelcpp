#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int main()
{
    std::string line;
    while(std::getline(std::cin, line))
    {
        std::istringstream iss(line);
        std::vector<int> v;
        int x;
        while(iss >> x)
            v.push_back(x);
        std::sort(v.begin(), v.end());
        for(int i : v)
            std::cout << i << " ";
        std::cout << std::endl;
    }
}
