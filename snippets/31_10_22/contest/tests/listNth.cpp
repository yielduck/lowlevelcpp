#include "../list.h"

namespace student
{
//#include "../recursive/listNth.h"
#include "../iterative/listNth.h"
}

#include "../cons.h"
#include "../recursive/destroyList.h"

#include <iostream>
int main()
{
    List const list = cons(1, cons(2, cons(3, cons(4, nullptr))));
    std::cout << student::listNth(list, 0u)->value;
    std::cout << student::listNth(list, 2u)->value;
    std::cout << student::listNth(list, 3u)->value;
    std::cout << (student::listNth(list, 4u) == nullptr);
    std::cout << (student::listNth(nullptr, 0u) == nullptr);
    std::cout << (student::listNth(nullptr, 1u) == nullptr);
    std::cout << std::endl;
    destroyList(list);
}
