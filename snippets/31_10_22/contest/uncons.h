ListUncons uncons(List const list)
{
    return {list, list->next};
}
