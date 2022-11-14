#include "../bits/list.h"
#include "../bits/iterator.h"

namespace student
{
#include "../solutions/min_element.h"
}

#include "../bits/cons.h"
#include "../bits/uncons.h"
#include "../bits/destroyList.h"

#include <iostream>
int main()
{
    List list = nullptr;

    int i;
    while(std::cin >> i)
        list = cons(i, list);

    ListIterator const begin = {list};
    ListIterator const end = {nullptr};
    ListIterator const min = student::min_element(begin, end);
    if(min == end)
        std::cout << "last" << std::endl;
    else
        std::cout << *min << std::endl;
    
    destroyList(list);
}
