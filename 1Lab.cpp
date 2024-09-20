#include <iostream>

int main() {
    int i;
    i = 69;
    int number = 72;
    i+=number;
    int massive[3] = {};
    int* iPointer = &i;
    number = *iPointer;
    *iPointer = 15;
    iPointer = massive;
    iPointer += 2;
    massive[0] = 5;
    *iPointer = 6;

    std::cout<<i<<"|"<<number<<"|"<<massive[0]<<"|"<<massive[1]<<"|"<<massive[2]<<"|"<<iPointer;
    return 0;
}