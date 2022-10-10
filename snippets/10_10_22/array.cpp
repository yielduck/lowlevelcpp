#include <algorithm>
#include <numeric>
#include <array>

namespace my
{

template<typename T, std::size_t N>
struct array
{
    T array[N];

    using      value_type = T;
    using       size_type = std::size_t;

    using        iterator = T       *;
    using  const_iterator = T const *;

    using       reference = T       &;
    using const_reference = T const &;

    T       *       data        ()                  {return array;}
    T const *       data        ()            const {return array;}

    size_type       size        ()            const {return N;}
    bool            empty       ()            const {return N == 0u;}

    iterator        begin       ()                  {return array;}
    iterator        end         ()                  {return array + N;}

    const_iterator  begin       ()            const {return array;}
    const_iterator  end         ()            const {return array + N;}

    reference       operator[]  (size_type i)       {return array[i];}
    const_reference operator[]  (size_type i) const {return array[i];}

    reference       front       ()                  {return array[0];}
    reference       back        ()                  {return array[N - 1u];}

    const_reference front       ()            const {return array[0];}
    const_reference back        ()            const {return array[N - 1u];}
};

}

#include <iostream>
int main()
{
    using Jopa = int;
    my::array<Jopa, 6> a = {5, 4, 3, 2, 1, 0};

    int sum = std::accumulate(a.begin(), a.end(), 0);
    std::cout << sum << std::endl;
    std::sort(a.begin(), a.end());

    for(int i : a)
        std::cout << i << " ";
    std::cout << std::endl;
}
