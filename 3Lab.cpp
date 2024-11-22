#include<array>

struct Leg
{
    int length;  //обЪект типа int
};

struct Arm
{
    int power;  //обЪект типа int
};

struct Person
{
    std::array<Leg, 2> legs;    //Массив который содержит в себе 2 объекта типа Leg
    Arm arms[2];    //Массив который содержет в себе 2 объекта типа Arm
};

int main()
{
    Person person;  //Объект типа Person
}

//10 объектов и 5 типа