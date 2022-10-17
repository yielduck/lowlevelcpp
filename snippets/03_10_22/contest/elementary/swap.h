inline void swap(int * const pa, int * const pb)
{
    int const a = *pa;
    *pa = *pb;
    *pb = a;
}
