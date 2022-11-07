#include "../list.h"

namespace student
{
#include "../iterative/reverseList.h"
}

#include "../cons.h"
#include "../recursive/destroyList.h"

#include <iostream>
int main()
{
    int const N = 100000;
    List list = student::reverseList(nullptr);
    for(int i = 0; i < N; ++i)
        list = cons(i, list);
    list = student::reverseList(list);
    bool good = true;
    Node *node = list;
    for(int i = 0; i < N; ++i)
    {
        good &= i == node->value;
        node = node->next;
    }
    std::cout << good << std::endl;
    destroyList(list);
}
