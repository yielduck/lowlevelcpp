#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string line;
    std::getline(std::cin, line);
    auto const it = std::find(line.begin(), line.end(), ' ');
    if(it == line.end())
        std::cout << "not found" << std::endl;
    else
        std::cout << it - line.begin() << std::endl;
}
