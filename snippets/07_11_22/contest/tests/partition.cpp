#include "../bits/list.h"
#include "../bits/iterator.h"

namespace student
{
#include "../solutions/partition.h"
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

    auto const pred = [](int x) {return x >= 0;};
    ListPair const pair = student::partition(list, pred);

    bool good = true;
    for(int const i : pair.first)
        good &= pred(i);
    for(int const i : pair.second)
        good &= !pred(i);
    std::cout << good << std::endl;
    
    destroyList(pair.first);
    destroyList(pair.second);
}
