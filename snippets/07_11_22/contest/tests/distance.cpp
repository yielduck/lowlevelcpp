#include "../bits/list.h"
#include "../bits/iterator.h"

namespace student
{
#include "../solutions/distance.h"
}

#include "../bits/cons.h"
#include "../bits/uncons.h"
#include "../bits/destroyList.h"

#include <iostream>
int main()
{
    List const list = cons(1, cons(2, cons(3, cons(4, nullptr))));

    ListIterator const begin = {list};
    ListIterator const end = {nullptr};
    std::cout << student::distance(begin, end);
    std::cout << student::distance({list->next}, end);
    std::cout << student::distance(begin, begin);
    std::cout << student::distance(end, end);
    std::cout << std::endl;
    
    destroyList(list);
}
