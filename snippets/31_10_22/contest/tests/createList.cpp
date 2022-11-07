#include "../list.h"
#include "../range.h"

namespace student
{
//#include "../recursive/createList.h"
#include "../iterative/createList.h"
}

#include "../recursive/destroyList.h"

#include <iostream>
int main()
{
    int const a[] = {1, 2, 3, 4, 5};
    List const list = student::createList({a, a + 5});
    for(Node *node = list; node != nullptr; node = node->next)
        std::cout << node->value;
    std::cout << std::endl;
    destroyList(list);
}
