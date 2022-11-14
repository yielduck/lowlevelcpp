#include "../bits/list.h"
#include "../bits/iterator.h"

namespace student
{
#include "../solutions/iter_swap.h"
}

#include "../bits/cons.h"
#include "../bits/uncons.h"
#include "../bits/destroyList.h"

#include <iostream>
int main()
{
    List const list = cons(1, cons(2, cons(3, cons(4, nullptr))));

    ListIterator const begin = {list};
    ListIterator const mid = {list->next->next};
    student::iter_swap(mid, mid);
    student::iter_swap(mid, begin);
    std::cout << *begin << *mid << std::endl;

    destroyList(list);
}
