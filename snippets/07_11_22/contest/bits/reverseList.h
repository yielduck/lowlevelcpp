List reverseList(List list)
{
    List accum = nullptr;
    while(list != nullptr)
    {
        auto const u = uncons(list);
        accum = prepend(u.head, accum);
        list = u.tail;
    }
    return accum;
}
