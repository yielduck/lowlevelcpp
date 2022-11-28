Tree createTree(int const * const begin, int const * const end)
{
    if(begin == end)
        return nullptr;
    int const * const mid = begin + (end - begin) / 2;
    Tree const left  = createTree(begin  , mid);
    Tree const right = createTree(mid + 1, end);
    return cons(left, *mid, right);
}
