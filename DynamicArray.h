#pragma once
#include<span>
#include<assert.h>

template<typename T>
class DynamicArray
{
    size_t capacity;
    size_t length;
    T* massive;


    public:
    /// @brief 
    /// Create array with capacity == 4
    /// @return 
    DynamicArray() : capacity(4), length(0)
    {
        massive = new T[capacity];
    }

    DynamicArray(size_t capacity) : capacity(capacity), length(0)
    {
        massive = new T[capacity];
    }

    DynamicArray(DynamicArray& copy) : capacity(copy.capacity), length(copy.length)
    {
        massive = new T[capacity];
        for (size_t i = 0; i < length; i++)
        {
            massive[i] = copy[i];
        }
    }

    DynamicArray(DynamicArray&& move) : capacity(move.capacity), length(move.length)
    {
        massive = move.massive;
        move.massive = nullptr;
    }

    inline DynamicArray& operator=(DynamicArray& right)
    {
        this->capacity = right.capacity;
        this->length = right.length;
        delete[] this->massive;
        this->massive = new T[capacity];
        for (size_t i = 0; i < right.length; ++i)
        {
            this->massive[i] = right.massive[i];
        }
        return *this;
    }

    inline DynamicArray& operator= (DynamicArray&& right)
    {
        this->capacity = right.capacity;
        this->length = right.length;
        delete[] this->massive;
        this->massive = right.massive;
        right.massive = nullptr;
        return *this;
    }

    // inline static DynamicArray createDynamicArrayWithCapacity(size_t length)
    // {
    //     return {.massive = new T[length], .capacity = length, .length = 0};
    // }

    /// @brief 
    /// Create array with capacity == 4
    /// @return 
    // inline static DynamicArray createDynamicArray()
    // {
    //     return {.massive = new T[4], .capacity = 4, .length = 0};
    // }

    DynamicArray& add(T item);
    
    ~DynamicArray()
    {
        delete[] massive;
    }

    inline T& operator[] (size_t x)
    {
        assert(x<length);
        return massive[x];
    }

    inline std::span<T> getCurrentSpan()
    {
        return std::span<T>{massive,length};
    }

    size_t getCapacity()
    {
        return capacity;
    }

    size_t getLength()
    {
        return length;
    }

    T* begin()
    {
        return massive;
    }

    T* end()
    {
        return massive+length;
    }

};