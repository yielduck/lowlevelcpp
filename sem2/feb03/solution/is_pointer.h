template<typename T>
struct is_pointer
{
    static constexpr bool value = false;
};
template<typename T>
struct is_pointer<T *>
{
    static constexpr bool value = true;
};
template<typename T>
struct is_pointer<T * const>
{
    static constexpr bool value = true;
};
