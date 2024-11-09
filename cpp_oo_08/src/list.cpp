#include "../include/list.hh"

template <typename T>
inline void List<T>::forEach(std::function<void(const T &)> callback) const
{
    for (size_t i = 0; i < length; i++)
    {
        callback(data[i]);
    }
}