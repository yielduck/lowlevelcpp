template<typename T>
struct remove_pointer
{
    using type = T;
};
template<typename T>
struct remove_pointer<T *>
{
    using type = T;
};
template<typename T>
struct remove_pointer<T * const>
{
    using type = T;
};
