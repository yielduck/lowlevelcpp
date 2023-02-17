#include <cstddef>

namespace student
{
template<typename T>
class span
{
    T *pBegin;
    T *pEnd;
public:
    using size_type = std::size_t;
    using iterator  = T *;

    span();
    span(T *begin, T *end);
    span(T *begin, size_type count);
    template<std::size_t N>
    span(T (&)[N]);

    T *          data() const;
    size_type    size() const;

    bool        empty() const;

    iterator    begin() const;
    iterator      end() const;

    T &operator[](size_type) const;

    span subspan(size_type offset, size_type count = -1) const;
};

#include "../solution/span.h"
}

struct Test
{};

#include <iostream>
int main()
{
    student::span<Test> emptySpan;
    for(Test i : emptySpan)
        std::cout << &i;
    std::cout << emptySpan.size() << ' ' << emptySpan.empty() << std::endl;
    
    int const a[] = {1, 2, 3, 4, 5};
    auto const test = [&](auto const &span)
    {
        for(int i : span)
            std::cout << i << ' ';
        std::cout << span.size() << ' ' << span.empty() << ' ' << span.data() - a << std::endl;
    };
    test(student::span<int const>(a).subspan(2   ));
    test(student::span<int const>(a).subspan(1, 3));
    test(student::span<int const>(a + 1, 2));
    test(student::span<int const>(a, a + 5));
}
