#include <iostream>

int badPath(int const * const begin, int const * const end)
{
    if(end - begin < 3)
        return 0;
    int const cost[] =
    {
        begin[0] + badPath(begin + 1, end),
        begin[1] + badPath(begin + 2, end),
        begin[2] + badPath(begin + 3, end),
    };
    return std::max(std::max(cost[0], cost[1]), cost[2]);
}

int main()
{
    int n;
    std::cin >> n;

    int cell[100];
    for(int i = 0; i < n; ++i)
        std::cin >> cell[i];

    int sum = 0;
    for(int i = 0; i < n;)
    {
        if(cell[i] >= 0)
        {
            sum += cell[i++];
            continue;
        }
        int j = i + 1;
        for(; j < n; ++j)
            if(cell[j] >= 0)
                break;
        sum += badPath(cell + i, cell + j);
        i = j;
    }
    std::cout << sum << std::endl;
}
