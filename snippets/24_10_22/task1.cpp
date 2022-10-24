#include <iostream>

int main()
{
    int stepCount;
    std::cin >> stepCount;

    int position = 0;
    for(int i = 0; i < stepCount; ++i)
    {
        int step;
        std::cin >> step;

        position += i % 2 == 0
            ?  step
            : -step;
    }
    std::cout << position << std::endl;
}
