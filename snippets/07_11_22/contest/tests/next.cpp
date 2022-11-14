#include "../bits/list.h"
#include "../bits/iterator.h"

namespace student
{
#include "../solutions/next.h"
}

#include "../bits/cons.h"
#include "../bits/uncons.h"
#include "../bits/prepend.h"
#include "../bits/destroyList.h"

#include <iostream>
int main()
{
    List const list = cons(1, cons(2, cons(3, cons(4, nullptr))));

    ListIterator const begin = {list};
    ListIterator const end = {nullptr};
    std::cout << (student::next(  end, 0) == end);
    std::cout << (student::next(begin, 4) == end);
    std::cout << (student::next(begin, 0) == begin);
    std::cout << (student::next(begin   ) == ListIterator{list->next});
    std::cout << (student::next(begin, 2) == ListIterator{list->next->next});
    std::cout << std::endl;
    
    destroyList(list);
}
