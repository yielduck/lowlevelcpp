#include <cstdint>
#include <utility>

#include <iostream>

struct Test
{
    int value;
public:
    Test(int a = 0)
        : value(a)
    {
        std::cout << "constructing " << value << std::endl;
    }
    Test(Test const &other)
        : value(other.value)
    {
        std::cout << "copy-constructing " << value << std::endl;
    }
    Test(Test &&other)
        : value(other.value)
    {
        std::cout << "move-constructing " << value << std::endl;
        other.value = 0;
    }
    Test &operator=(Test const &other)
    {
        std::cout << "copy-assigning " << other.value << " to " << value << std::endl;
        if(&other != this)
            value = other.value;
        return *this;
    }
    Test &operator=(Test &&other)
    {
        std::cout << "move-assigning " << other.value << " to " << value << std::endl;
        if(&other != this)
        {
            value = other.value;
            other.value = 0;
        }
        return *this;
    }
    ~Test()
    {
        std::cout << "destroying " << value << std::endl;
    }
    int get() const;
};
int Test::get() const {return value;}

void print(int &)
{
    std::cout << "int &" << std::endl;
}
void print(int const &)
{
    std::cout << "int const &" << std::endl;
}
void print(int &&)
{
    std::cout << "int &&" << std::endl;
}
void print(int const &&)
{
    std::cout << "int const &&" << std::endl;
}

int main()
{
    Test test1(100);
    Test test2(110);
    Test copy1(test1);
    Test move2(static_cast<Test &&>(test2));

    Test test;
    test = copy1;
    test = std::move(copy1);
}
