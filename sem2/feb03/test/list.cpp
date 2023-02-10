template<typename T>
struct Node
{
    T value;
    Node<T> *next;
};
template<typename T>
using List = Node<T> *;

#include <cstdlib>
namespace student
{
#include "../solution/list.h"
}

#include <iostream>
int main()
{
    auto const list =
        student::cons("templates",
        student::cons("are",
        student::cons("so",
        student::cons("damn",
        student::cons("cool"
    )))));
    for(auto it = list; it != nullptr; it = it->next)
        std::cout << it->value << ' ';
    std::cout << std::endl;
    student::destroyList(list);
}
