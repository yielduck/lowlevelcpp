#include "../list.h"

namespace student
{
#include "../iterative/mergeList.h"
}

#include "../cons.h"
#include "../recursive/destroyList.h"

#include <iostream>
int main()
{
    int const N = 10000;
    List list1 = nullptr;
    List list2 = nullptr;
    List list3 = nullptr;
    for(int i = N - 1; i >= 0; --i)
    {
        list1 = cons(2 * i    , list1);
        list2 = cons(2 * i + 1, list2);
        list3 = cons(2 * N + i, list3);
    }
    List const list = student::mergeList
    (
        list3,
        student::mergeList
        (
            list1,
            student::mergeList
            (
                nullptr,
                list2
            )
        )
    );
    bool good = true;
    Node *node = list;
    for(int i = 0; i < 3 * N; ++i)
    {
        good &= (i == node->value);
        node = node->next;
    }
    std::cout << good << std::endl;
    destroyList(list);
}
