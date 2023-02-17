template<typename T>
smart_ptr<T>::~smart_ptr() {delete ptr;}
template<typename T>
smart_ptr<T>::smart_ptr() : ptr(nullptr) {}
template<typename T>
smart_ptr<T>::smart_ptr(smart_ptr<T> &&other)
    : ptr(other.ptr)
{
    other.ptr = nullptr;
}
template<typename T>
smart_ptr<T> &smart_ptr<T>::operator=(smart_ptr<T> &&other)
{
    if(this != &other)
    {
        this->~smart_ptr<T>();
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

template<typename T>
T *smart_ptr<T>::get() const {return ptr;}
template<typename T>
smart_ptr<T>::operator bool() const {return ptr != nullptr;}
template<typename T>
T *smart_ptr<T>::operator->() const {return ptr;}
template<typename T>
T &smart_ptr<T>::operator* () const {return *ptr;}
