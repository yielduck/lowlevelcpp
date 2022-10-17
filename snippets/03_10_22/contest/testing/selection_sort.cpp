#include "int_range.h"
namespace student
{
#include "../elementary/selection_sort.h"
}

#include <iostream>
#include <vector>
int main()
{
    std::vector<int> v;
    int x;
    while(std::cin >> x)
        v.push_back(x);

    IntRange const range =
    {
        .begin = &v[0],
        .end   = &v[0] + v.size(),
    };
    student::selection_sort(range);
    for(int const n : v)
        std::cout << n << " ";
    std::cout << std::endl;
}
