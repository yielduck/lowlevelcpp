inline void swap(int * const pa, int * const pb)
{
    int const a = *pa;
    *pa = *pb;
    *pb = a;
}
inline void siftdown(IntRange const heap, int const i)
{
    int const n = heap.end - heap.begin;
    int const left  = 2 * i + 1;
    int const right = 2 * i + 2;
    if(left >= n)
        return;
    int const child = right < n
                    && heap.begin[left] < heap.begin[right]
        ? right
        : left;
    if(heap.begin[i] >= heap.begin[child])
        return;
    swap(heap.begin + i, heap.begin + child);
    siftdown(heap, child);
}
