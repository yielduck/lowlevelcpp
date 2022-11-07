Node *listNth(List const list, unsigned int const n)
{
    return n == 0 || list == nullptr
        ? list
        : listNth(list->next, n - 1u);
}
