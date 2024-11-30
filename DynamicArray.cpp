#include "DynamicArray.h"

template<typename T>
DynamicArray<T>& DynamicArray<T>::add(T item)
    {
        if (length == capacity)
        {
            T* temp = new T[max(capacity*2, 1)];
            for (size_t i = 0; i<capacity;i++)
            {
                temp[i] = massive[i];
            }
            capacity *=2;
            delete[] massive;
            massive = temp;
        }
        massive[length] = item;
        ++length;
        return *this;
    }


template class DynamicArray<int>;