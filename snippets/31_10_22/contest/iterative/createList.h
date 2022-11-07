#include "../cons.h"
List createList(IntConstRange const range)
{
    List list = nullptr;
    for(int const *it = range.end - 1; it >= range.begin; --it)
        list = cons(*it, list);
    return list;
}
