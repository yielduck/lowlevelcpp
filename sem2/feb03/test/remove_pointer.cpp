namespace student
{
#include "../solution/remove_pointer.h"
}

template<typename T, typename U>
struct is_same
{
    static constexpr bool value = false;
};
template<typename T>
struct is_same<T, T>
{
    static constexpr bool value = true;
};

struct Test {};

#include <iostream>
int main() 
{
    std::cout << std::boolalpha;
    std::cout << "is_same<Test        , student::remove_pointer<Test                >::type>::value == "
              <<  is_same<Test        , student::remove_pointer<Test                >::type>::value << std::endl
              << "is_same<Test        , student::remove_pointer<Test *              >::type>::value == "
              <<  is_same<Test        , student::remove_pointer<Test *              >::type>::value << std::endl
              << "is_same<Test * const, student::remove_pointer<Test * const * const>::type>::value == "
              <<  is_same<Test * const, student::remove_pointer<Test * const * const>::type>::value << std::endl
              << "is_same<int         , student::remove_pointer<int          * const>::type>::value == "
              <<  is_same<int         , student::remove_pointer<int          * const>::type>::value << std::endl
              << "is_same<int const   , student::remove_pointer<int    const * const>::type>::value == " 
              <<  is_same<int const   , student::remove_pointer<int    const * const>::type>::value << std::endl;
}
