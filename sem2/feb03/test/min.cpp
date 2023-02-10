namespace student
{
#include "../solution/min.h"
}

struct pair
{
    int first, second;
    bool operator<(pair const &other) const
    {
        return first == other.first
            ? second < other.second
            : first < other.first;
    }
};

#include <string>
#include <iostream>
int main()
{
    pair p1 = {1, 3};
    pair p2 = {1, 2};
    std::string s1 = "anus";
    std::string s2 = "psa";
    auto const p = student::min(p1, p2);
    std::cout << p.first << ' ' << p.second << std::endl;
    std::cout << student::min(s1, s2) << std::endl;
}
