#include "../bits/list.h"
#include "../bits/iterator.h"

namespace student
{
#include "../solutions/selection_sort.h"
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

    student::selection_sort(begin(list), end(list));
    if(list == nullptr)
        std::cout << "empty";
    for(int const i : list)
        std::cout << i << " ";
    std::cout << std::endl;
    
    destroyList(list);
}
