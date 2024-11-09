#ifndef LIST_H
#define LIST_H

#include <functional>

template <class T>
class List
{
private:
    size_t length;
    T *data;

public:
    List(T *&data, const size_t &length) : data(data), length(length) {};
    ~List()
    {
        delete[] data;
    };

    void forEach(std::function<void(const T &data)> callback) const;
};

#include "../src/list.cpp"

#endif
