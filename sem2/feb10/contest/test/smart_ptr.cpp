namespace student
{
template<typename T>
class smart_ptr
{
    T *ptr;
public:
    ~smart_ptr();
    smart_ptr();
    template<typename... Args>
    smart_ptr(Args &&... args)
        : ptr(new T(static_cast<Args &&>(args)...))
    {}
    smart_ptr(smart_ptr<T> const &) = delete;
    smart_ptr<T> &operator=(smart_ptr<T> const &) = delete;
    smart_ptr(smart_ptr<T> &&);
    smart_ptr<T> &operator=(smart_ptr<T> &&);
    T *get() const;
    operator bool() const;
    T *operator->() const;
    T &operator* () const;
};
    
#include "../solution/smart_ptr.h"
}

#include <iostream>
#include <utility>
int main()
{
    using P = std::pair<int, int>;
    auto const print = [](student::smart_ptr<P> const &p)
    {
        if(p && p->first == p.get()->first && p->first == (*p).first)
            std::cout << p->first << ' ';
        if(p && p->second == p.get()->second && p->second == (*p).second)
            std::cout << p->second << ' ';
        std::cout << std::endl;
    };
    student::smart_ptr<P> ptr = {1, 2};
    print(ptr);
    ptr->first = 10;
    print(ptr);

    student::smart_ptr<P> p0;
    student::smart_ptr<P> p1(std::move(p0));
    print(p0);
    print(p1);

    ptr = std::move(ptr);
    print(ptr);

    ptr = std::move(p1);
    print(p1);
    print(ptr);

    student::smart_ptr<P> p3(3, 5);
    student::smart_ptr<P> p2(std::move(p3));
    print(p2);
    print(p3);
}
