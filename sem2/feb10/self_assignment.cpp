#include <iostream>

template<typename I>
void iter_swap(I const a, I const b)
{
    auto tmp = std::move(*a);
    *a = std::move(*b);
    *b = std::move(tmp);
}

template<typename I>
auto max_element(I const begin, I const end)
{
    auto max = begin;
    for(auto it = begin + 1; it < end; ++it)
        if(*max < *it)
            max = it;
    return max;
}
template<typename I>
void selection_sort(I const begin, I const end)
{
    for(auto it = begin; it + 1 < end; ++it)
        iter_swap(it, max_element(it, end));
}

struct Test
{
    int value;

    Test(int x = 0) : value(x) {}
    Test(Test &&other) : value(other.value) {other.value = 0;}
    Test &operator=(Test &&other)
    {
        if(&other != this)
            std::construct_at(this, static_cast<Test &&>(other));
        else
            std::cout << "self-assignment" << std::endl;
        return *this;
    }
    bool operator<(Test const &other) const {return value < other.value;}
};

int main()
{
    Test test[] = {{1}, {2}, {3}, {4}, {5}};
    selection_sort(test, test + 5);

    for(Test const &t : test)
        std::cout << t.value << ' ';
    std::cout << std::endl;
}
