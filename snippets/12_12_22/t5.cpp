Unit *forward(Unit *curr)
{
    return curr == curr->next->prev
        && curr != curr->next
        ? forward(curr->next)
        : curr;
}
Unit *backward(Unit *curr)
{
    return curr == curr->prev->next
        && curr != curr->prev
        ? backward(curr->prev)
        : curr;
}
void Fix(Unit* u)
{
    Unit *a = forward(u);
    Unit *b = backward(u);
    a->next = b;
    b->prev = a;
}
