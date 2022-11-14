#include "../bits/list.h"

namespace student
{
#include "../solutions/concatList.h"
}

#include "../bits/cons.h"
#include "../bits/uncons.h"
#include "../bits/prepend.h"
#include "../bits/destroyList.h"
#include "../bits/reverseList.h"

#include <iostream>
#include <sstream>
int main()
{
    List list[2] = {nullptr, nullptr};
    
    int i;
    std::string line;
    for(int j = 0; j < 2; ++j)
    {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        while(iss >> i)
            list[j] = cons(i, list[j]);
        list[j] = reverseList(list[j]);
    }
    List const sum = student::concatList(list[0], list[1]);
    for(auto it = sum; it != nullptr; it = it->next)
        std::cout << it->value << " ";
    std::cout << std::endl;

    destroyList(sum);
}
