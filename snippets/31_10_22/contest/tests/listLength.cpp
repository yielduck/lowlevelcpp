#include "../list.h"

namespace student
{
#include "../recursive/listLength.h"
}

#include "../cons.h"
#include "../recursive/destroyList.h"

#include <iostream>
int main()
{
    List const list = cons(1, cons(2, cons(3, cons(4, nullptr))));
    std::cout << student::listLength(nullptr) << std::endl;
    std::cout << student::listLength(list) << std::endl;
    destroyList(list);
}
