#include <iostream>
#include <assert.h>
#include <span>
#include "DynamicArray.h"



void static test1()
{
    DynamicArray<int> arr = DynamicArray<int>(10);
    assert(arr.getCapacity() == 10);
}

void static test2()
{
    DynamicArray<int> arr = DynamicArray<int>();
    assert(arr.getLength() == 0);
    arr.add(5);
    assert(arr.getLength() == 1);
}

void static test3()
{
    DynamicArray arr = DynamicArray<int>(1);
    arr.add(5);
    assert(arr.getCapacity() == 1);
    arr.add(10);
    assert(arr.getCapacity() == 2);
    arr.add(20);
    assert(arr.getCapacity() == 4);
}

void static test4()
{
    DynamicArray arr = DynamicArray<int>();
    arr.add(5);
    int el = arr[0];
    assert(el == 5);
}

void static test5()
{
    DynamicArray<int> arr{};
    arr.add(5);
    arr.add(6);
    arr.add(7);

    std::span<int> span = arr.getCurrentSpan();

    assert(span.size() == 3);
    assert(span[0] == 5);
    assert(span[1] == 6);
    assert(span[2] == 7);
}



int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();

    return 0;
}