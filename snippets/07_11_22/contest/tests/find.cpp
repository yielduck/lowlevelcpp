#include "../bits/list.h"
#include "../bits/iterator.h"

namespace student
{
#include "../solutions/find.h"
}

#include "../bits/cons.h"
#include "../bits/uncons.h"
#include "../bits/prepend.h"
#include "../bits/destroyList.h"
#include "../bits/reverseList.h"
#include "../solutions/iterator.h"
#include "../solutions/distance.h"

#include <iostream>
int main()
{
    List list = nullptr;

    int i, n;
    std::cin >> n;
    while(std::cin >> i)
        list = cons(i, list);
    list = reverseList(list);

    ListIterator const it = student::find(begin(list), end(list), n);
    if(it == end(list))
        std::cout << "not found";
    else
        std::cout << "distance(begin, it) = " << distance(begin(list), it);
    std::cout << std::endl;

    destroyList(list);
}
