#include <iostream>

int main()
{
    char field[13] = {};

    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 4; ++j)
            field[4 * i + j] = std::cin.get();

    // field: 0 1  2 [ 3]
    //        4 5  6 [ 7]
    //        8 9 10 [11]
    int const pattern[8][3] =
    {
        // horizontal:
        {0, 1,  2},
        {4, 5,  6},
        {8, 9, 10},
        // vertical:
        {0, 4,  8},
        {1, 5,  9},
        {2, 6, 10},
        // diagonal:
        {0, 5, 10},
        {2, 5,  8},
    };
    for(int i = 0; i < 8; ++i)
    {
        if(field[pattern[i][0]] + field[pattern[i][1]] + field[pattern[i][2]] != 'x' + 'x' + ' ')
            continue;

        for(int j = 0; j < 3; ++j)
            field[pattern[i][j]] = 'x';
        std::cout << field << std::endl;
        return 0;
    }
    std::cout << -1 << std::endl;
}
