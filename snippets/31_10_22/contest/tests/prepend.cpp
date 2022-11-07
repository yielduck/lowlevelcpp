#include "../list.h"

namespace student
{
#include "../prepend.h"
}

#include "../cons.h"
#include "../recursive/destroyList.h"

#include <iostream>
int main()
{
    List list = cons(1, cons(2, cons(3, cons(4, nullptr))));

    list = student::prepend(cons(5, nullptr), list);

    for(Node *node = list; node != nullptr; node = node->next)
        std::cout << node->value;
    std::cout << std::endl;

    destroyList(list);
}
