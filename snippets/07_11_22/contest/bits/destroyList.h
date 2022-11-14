void destroyList(List const list)
{
    if(list == nullptr)
        return;
    auto const [x, xs] = uncons(list);

    std::free(x);
    destroyList(xs);
}
