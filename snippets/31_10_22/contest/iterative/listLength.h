unsigned int listLength(List list)
{
    unsigned int length = 0u;
    for(; list != nullptr; list = list->next)
        ++length;
    return length;
}
