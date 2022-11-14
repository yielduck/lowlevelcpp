#include "../bits/list.h"
#include "../bits/iterator.h"

namespace student
{
#include "../solutions/quicksort.h"
}

#include "../bits/cons.h"
#include "../bits/uncons.h"
#include "../bits/destroyList.h"
#include "../solutions/iterator.h"

#include <iostream>
int main()
{
    List list = nullptr;

    int i;
    while(std::cin >> i)
        list = cons(i, list);

    auto const cmp = [](int x, int y) {return x > y;};
    list = student::quicksort(list, cmp);

    for(int const i : list)
        std::cout << i << " ";
    std::cout << std::endl;

    destroyList(list);
}
