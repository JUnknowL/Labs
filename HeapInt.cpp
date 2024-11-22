#include "HeapInt.h"
#include <iostream>

    HeapInt::HeapInt(const HeapInt& hello) : heapValue(hello.heapValue){};
    HeapInt::HeapInt(HeapInt&& hello) {
        *this = std::move(hello);
    };
    void HeapInt::operator=(const HeapInt& hello)
    {
        heapValue = hello.heapValue;
    };
    void HeapInt::operator=(HeapInt&& hello)
    {
        heapValue = hello.heapValue;
        hello.heapValue = nullptr;
    };