#include <new>

class Test
{
    int *ptr;
public:

    Test(int value = 0)
        : ptr(new int(value))
    {}

    Test(Test const &test)
        : ptr(new int(*test.ptr))
    {}

    Test(Test      &&test)
        : ptr(test.ptr)
    {
        test.ptr = nullptr;
    }

    Test &operator=(Test const &test)
    {
        if(this != &test)
        {
            this->~Test();
            new (this) Test(test);
        }
        return *this;
    }
    Test &operator=(Test      &&test)
    {
        if(this != &test)
        {
            this->~Test();
            new (this) Test(static_cast<Test &&>(test));
        }
        return *this;
    }

    ~Test() {delete ptr;}

    int value() const {return *ptr;}
};

#include <iostream>
int main()
{
    Test test;
    std::cout << test.value() << std::endl;
}
