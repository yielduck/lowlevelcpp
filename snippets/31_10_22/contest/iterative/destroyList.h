#include "../uncons.h"
void destroyList(List list)
{
    while(list != nullptr)
    {
        auto const [x, xs] = uncons(list);
        std::free(x);
        list = xs;
    }
}
