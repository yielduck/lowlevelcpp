List concatList(List const left, List const right)
{
    if(left == nullptr)
        return right;

    Node *last = left;
    while(last->next != nullptr)
        last = last->next;
    last->next = right;
    return left;
}
