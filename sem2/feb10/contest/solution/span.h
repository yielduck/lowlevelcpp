template<typename T>
span<T>::span()
    : pBegin(nullptr)
    , pEnd  (nullptr)
{}
template<typename T>
span<T>::span(T *begin, T *end)
    : pBegin(begin)
    , pEnd  (end)
{}
template<typename T>
span<T>::span(T *begin, size_type count)
    : pBegin(begin)
    , pEnd  (begin + count)
{}
template<typename T>
template<std::size_t N>
span<T>::span(T (&arr)[N])
    : pBegin(arr)
    , pEnd  (arr + N)
{}
template<typename T>
T *span<T>::data() const {return pBegin;}
template<typename T>
std::size_t span<T>::size() const {return pEnd - pBegin;}
template<typename T>
bool span<T>::empty() const {return pBegin == pEnd;}
template<typename T>
T *span<T>::begin() const {return pBegin;}
template<typename T>
T *span<T>::  end() const {return pEnd;}
template<typename T>
T &span<T>::operator[](size_type const i) const {return pBegin[i];}
template<typename T>
span<T> span<T>::subspan(size_type const offset, size_type const count) const
{
    return
    {
        pBegin + offset,
        count == size_type(-1)
            ? pEnd
            : pBegin + offset + count,
    };
}
