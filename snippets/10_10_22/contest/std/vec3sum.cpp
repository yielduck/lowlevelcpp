#include <cstdio>

int main()
{
    int sum[3] = {0, 0, 0};
    int x[3];
    while(std::scanf("(%d, %d, %d)\n", x, x + 1, x + 2) == 3)
        for(int i = 0; i < 3; ++i)
            sum[i] += x[i];
    std::printf("(%d, %d, %d)\n", sum[0], sum[1], sum[2]);
}
