Node *listNth(List list, unsigned int n)
{
    for(; list != nullptr; list = list->next)
        if(0u == n--)
            break;
    return list;
}
