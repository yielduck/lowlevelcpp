int dereference(void const * const ptr)
{
    return *static_cast<int const *>(ptr);
}
