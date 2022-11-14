#include "../bits/list.h"
#include "../bits/iterator.h"

namespace student
{
#include "../solutions/iterator.h"
}

#include "../bits/cons.h"
#include "../bits/uncons.h"
#include "../bits/destroyList.h"

using student::begin;
using student::  end;

#include <iostream>
int main()
{
    List const list = cons(1, cons(2, cons(3, cons(4, nullptr))));

    for(int const i : list)
        std::cout << i << " ";
    std::cout << std::endl;
}
