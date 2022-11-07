List prepend(Node * const head, List const tail)
{
    head->next = tail;
    return head;
}
