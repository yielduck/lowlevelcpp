#include <algorithm>
#include <numeric>
#include <array>

namespace my
{

template<typename T, std::size_t N>
struct array
{
    T array[N];

    using value_type = T;
    using size_type = std::size_t;

    using iterator = T *;
    using const_iterator = T const *;

    iterator begin() {return array;}
    iterator end() {return array + N;}

    size_type size() const {return N;}
    iterator data() {return array;}

    T       &operator[](size_type i)       {return array[i];}
    T const &operator[](size_type i) const {return array[i];}
};

}

#include <iostream>
int main()
{
    using Jopa = int;
    my::array<Jopa, 6> a = {5, 4, 3, 2, 1, 0};

    int sum = std::accumulate(a.begin(), a.end(), 0);
    std::sort(a.begin(), a.end());

    for(int i : a)
        std::cout << i << " ";
    std::cout << std::endl;
}
