struct Pair
{
    int first;
    int second;
};

int pairSum(Pair const p)
{
    return p.first + p.second;
}

bool operator<(Pair const p1, Pair const p2)
{
    return p1.first != p2.first
        ? p1.first  < p2.first
        : p1.second < p2.second;
}

#include <iostream>
int main()
{
    Pair const lesser = {1, 2};
    Pair const bigger =
    {
        .first = 3,
        .second = 4,
    };
    std::cout << pairSum(bigger) << std::endl;
    std::cout << std::boolalpha << (lesser < bigger) << std::endl;
}
