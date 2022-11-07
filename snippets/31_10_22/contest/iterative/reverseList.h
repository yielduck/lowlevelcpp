#include "../prepend.h"
#include "../uncons.h"
List reverseList(List list)
{
    List accum = nullptr;
    while(list != nullptr)
    {
        auto const [x, xs] = uncons(list);
        accum = prepend(x, accum);
        list = xs;
    }
    return accum;
}
