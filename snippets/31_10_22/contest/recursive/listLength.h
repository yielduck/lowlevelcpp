unsigned int listLength(List const list)
{
    return list == nullptr
        ? 0u
        : 1u + listLength(list->next);
}
