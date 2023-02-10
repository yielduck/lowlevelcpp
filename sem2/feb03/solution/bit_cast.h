template<typename T, typename U>
T bit_cast(U const x)
{
    return *reinterpret_cast<T const *>(&x);
}
