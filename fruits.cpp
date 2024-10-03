#include <iostream>

struct FruitCounts
{ 
    int apples;
    int pears;
    int oranges;

};


void main()
{
    
    FruitCounts Fruits{};

    std::cout << "Apples:";
    std::cin >> Fruits.apples;

    std::cout << "Pears:";
    std::cin >> Fruits.pears;

    std::cout << "Oranges:";
    std::cin >> Fruits.oranges;

    bool temp;
    {
        bool apples = Fruits.apples>5;
        bool pears = Fruits.pears<8;
        bool oranges = Fruits.oranges>Fruits.apples*2;
        temp = apples&&pears&&oranges;
    }
    if (temp) std::cout<<"Hello";

}