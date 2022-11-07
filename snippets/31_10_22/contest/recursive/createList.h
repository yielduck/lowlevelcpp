#include "../cons.h"
List createList(IntConstRange const range)
{
    return range.begin == range.end
        ? nullptr
        : cons(*range.begin, createList({range.begin + 1, range.end}));
}
