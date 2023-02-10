template<typename T>
List<T> cons(T const value, List<T> const next = nullptr)
{
    return new Node<T>{value, next};
}
template<typename T>
void destroyList(List<T> const list)
{
    if(list == nullptr)
        return;
    destroyList(list->next);
    delete list;
}
