#include <stdlib.h>
#include <iostream>
#include <cstring>

struct TwoInts //Объявляем структуру TwoInts с элементами int a и b
{
    int a;
    int b;
};

struct StructWithArray  //Объявляем структуру StructWithArray с одномерным массивом из 4 элементов и указателем на int
{
    int arr[4];
    int* someNumber;
};

int main()  //Главная функция
{
    TwoInts i2 = { };   //Создаём пустую структуру TwoInts с именем i2
    i2.a = 5;  //В объекте структуры(TwoInts) с названием i2 значение a устанавливаем на 5
    i2.b = 7;  //В объекте структуры(TwoInts) с названием i2 значение b устанавливаем на 7

    std::cout << i2.a << std::endl; //Выводим значения
    std::cout << i2.b << std::endl;
    
    StructWithArray s = { };  //Создаём пустую структуру StructWithArray с именем s
    s.arr[0] = 10;   //В объекте структуры(StructWithArray) с названием s устанавливаем значение для первого элемента массива arr на 10

    StructWithArray s1 = { };//Создаём пустую структуру StructWithArray с именем s1
    s1.arr[0] = 15;  //В объекте структуры(StructWithArray) с названием s1 устанавливаем значение для первого элемента массива arr на 15


    StructWithArray* sPointer = &s; //Создаём указатель на (StructWithArray) sPointer и задаём ему значение на структурру s
    sPointer->arr[0] = 20; //Через указатель заходим в массив arr(из структуры s) и ставим первое значение на 20

    std::cout << s.arr[0] << std::endl;   //Выводим 1 элемент массива в объекте структуры s
    s.arr[0] = 25;   //В объекте структуры(StructWithArray) с названием s устанавливаем значение для первого элемента массива arr на 25
    std::cout << s.arr[0] << std::endl;//Выводим 1 элемент массива в объекте структуры s
    sPointer->arr[0] = 30; //Через указатель заходим в массив arr(из структуры s) и ставим первое значение на 30
    std::cout << s.arr[0] << std::endl;//Выводим 1 элемент массива в объекте структуры s

    sPointer = &s1;  //Указателю задаём значение на структурру s1
    sPointer->arr[0] = 35;//Через указатель заходим в массив arr(из структуры s1) и ставим первое значение на 35
    std::cout << s.arr[0] << std::endl;   //Выводим 1 элемент массива в объекте структуры s
    std::cout << s1.arr[0] << std::endl;  //Выводим 1 элемент массива в объекте структуры s1

    StructWithArray structArray[2] = { }; //Создаём одномерный массив из(StructWithArray) размером в 2 элемента
    structArray[0].arr[3] = 77;  //В массиве первой структуры из массива структур 4 значение ставим на 77
    structArray[1].someNumber = &structArray[0].arr[3];  //В указатель второй структуры из массива записываем адресс 4элемента массива из первой структуре в массиве

    sPointer = &s;    //Указателю задаём значение на структурру s
    int* pointer = &sPointer->arr[3];  //Создаём указатель на int и задаём ему адресс 4 элемента массива в структуре s
    s.arr[3] = 72;//В объекте структуры(StructWithArray) с названием s устанавливаем значение для 4 элемента массива arr на 72
    std::cout << *pointer; //выводим значение  4 элемента массива arr в структуре s

    StructWithArray memory;   ///Создаём пустую структуру StructWithArray с именем memory
    memset(&memory, 0, sizeof(StructWithArray));   //заполняет все значения в memory нулями
    return 0;
}