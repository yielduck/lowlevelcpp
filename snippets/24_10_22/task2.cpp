#include <iostream>

int main()
{
    int n;
    std::cin >> n;

    int sum = 0;
    for(int i = 0; i + 1 < n; ++i)
    {
        int elem;
        std::cin >> elem;
        sum += elem;
    }
    std::cout << (n * (n + 1)) / 2 - sum << std::endl;
}
