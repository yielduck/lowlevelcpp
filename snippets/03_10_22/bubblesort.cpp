#include <cstdlib>

struct IntRange
{
    int *begin;
    int *  end;
};
void swap(int * const pa, int * const pb)
{
    int const a = *pa;
    *pa = *pb;
    *pb = a;
}
void bubblesort(IntRange const range, auto compare)
{
    auto a = range.begin;
    auto const n = range.end - range.begin;
    for(auto i =     0u; i + 1 < n; ++i)
    for(auto j = i + 1u; j     < n; ++j)
        if(!compare(a[i], a[j]))
            swap(a + i, a + j);
}

#include <iostream>
int main()
{
    int a[] = {5, 2, 3, 1, 5};
    IntRange range = {a, a + 5};
    bubblesort(range, [](int x, int y){return x > y;});
    for(int x : a)
        std::cout << x << " ";
    std::cout << std::endl;
}
