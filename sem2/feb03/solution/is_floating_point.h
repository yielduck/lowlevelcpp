template<typename T>
struct is_floating_point
{
    static constexpr bool value = false;
};
template<>
struct is_floating_point<float>
{
    static constexpr bool value = true;
};
template<>
struct is_floating_point<double>
{
    static constexpr bool value = true;
};
template<>
struct is_floating_point<long double>
{
    static constexpr bool value = true;
};
