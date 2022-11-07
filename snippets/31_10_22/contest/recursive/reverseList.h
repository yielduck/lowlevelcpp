#include "../prepend.h"
#include "../uncons.h"
List reverseListImpl(List const accum, List const list)
{
    if(list == nullptr)
        return accum;
    auto const [x, xs] = uncons(list);
    return reverseListImpl(prepend(x, accum), xs);
}
List reverseList(List const list)
{
    return reverseListImpl(nullptr, list);
}
