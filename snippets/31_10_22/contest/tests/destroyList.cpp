#include "../list.h"

namespace student
{
//#include "../recursive/destroyList.h"
#include "../iterative/destroyList.h"
}

#include "../cons.h"

#include <iostream>
int main()
{
    List const list = cons(1, cons(2, cons(3, cons(4, nullptr))));
    
    std::cout << list->value << " ";
    std::cout << list->next->value << " ";
    std::cout << list->next->next->value << " ";
    std::cout << list->next->next->next->value << std::endl;
    student::destroyList(list);
    student::destroyList(nullptr);
}
