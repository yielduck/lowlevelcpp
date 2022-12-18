#include <iostream>
#include <vector>
int main()
{
    int F, N, M, D;
    std::cin >> F >> N >> M >> D;
    
    std::vector<int> target, real;
    for(int i = 0; i < N; ++i)
    {
        int x;
        std::cin >> x;
        target.push_back(x);
    }
    for(int i = 0; i < N; ++i)
    {
        int x;
        std::cin >> x;
        real.push_back(x);
    }
    int i = 0;
    for(; i < N && F > 0; ++i)
    {
        if(real[i] < target[i])
            F += M;
        if(real[i] > target[i])
            F -= D;
        F -= real[i];
    }
    std::cout << i << std::endl;
}
