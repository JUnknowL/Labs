#include <iostream>
#include <string>
#include <assert.h>
#include <array>

enum class Portrait{
    Lenin,
    Jeorge_Washington,
    Ghitler,
};

enum class Color{
    Blue,
    White,
    Red,
};

enum class WireColor{
    Red,
    Yellow,
    Green,
    Nothing,
};

const std::array<std::string_view,3> wireNames = {"Red","Yellow","Green"};

inline int Move(int num, int incr,const int length)
{
    incr = incr%length;
    return (length+num+incr)%length;
}

struct BombState
{
    Portrait portrait;
    Color color;
    bool tumbler;
    int16_t number;
};

int getNumberFromColor(Color color)
{
    switch (color)
        {
        case Color::Red:
            return 35;
            break;
        case Color::Blue:
            return 11;
            break;
        case Color::White:
            return 15;
            break;
        
        default:
            assert(false);
            break;
        }
}

WireColor Check(BombState bomb)
{

    if(bomb.portrait == Portrait::Lenin)
    {
        return WireColor::Nothing;
    }

    WireColor wireColor;

    if (bomb.portrait == Portrait::Ghitler)
    {
        bomb.color = static_cast<Color>(Move(static_cast<int>(bomb.color),1,3));
    }

    {
        int tempNumber = getNumberFromColor(bomb.color);
        
        

        if (bomb.number <  tempNumber)
        {
            wireColor = WireColor::Red;
        }
        else if ( bomb.number == tempNumber)
        {
            wireColor = WireColor::Green;
        }
        else
        {
            wireColor = WireColor::Yellow;
        }
    }

    if (bomb.tumbler)
    {
        wireColor = static_cast<WireColor>(Move(static_cast<int>(wireColor),-1,3));
    }

    if (bomb.number%4 == 0)
    {
        wireColor = static_cast<WireColor>(Move(static_cast<int>(wireColor),bomb.number/4,3));
    }

    return wireColor;
}

BombState KeyboardInput()
{
    Portrait portrait;
    std::string a;
    while (true)
    {
        std::cout<<"Enter portret name or it's number(Lenin,Jeorge_Washington,Ghitler):";
        std::getline(std::cin,a);
        if (a=="Lenin" || a=="1")
        {
            portrait = Portrait::Lenin;
        }
        else if (a == "Jeorge_Washington" || a=="2")
        {
            portrait = Portrait::Jeorge_Washington;
        }
        else if (a== "Ghitler" || a=="3")
        {
            portrait = Portrait::Ghitler;
        }
        else
        {
            std::cout << "Invaid input." << std::endl;
            continue;
        }
        break;
    }

    Color color;
    while (true)
    {
        std::cout<<"Enter color name or it's number(Blue,White,Red):";
        std::getline(std::cin,a);
        if (a=="Blue" || a=="1")
        {
            color = Color::Blue;
        }
        else if (a == "White" || a=="2")
        {
            color = Color::White;
        }
        else if (a== "Red" || a=="3")
        {
            color = Color::Red;
        }
        else
        {
            std::cout << "Invaid input." << std::endl;
            continue;
        }
        break;
    }
    


    bool tumbler;
    while(true)
    {
        std::cout << "Enter tumbler state(on/off):";
        std::getline(std::cin, a);
        if (a == "on" || a == "1")
        {
            tumbler = true;
        }
        else if (a == "off" || a == "2" || a == "0")
        {
            tumbler = false;
        }
        else
        {
            std::cout << "Invaid input." << std::endl;
            continue;
        }
        break;
    }

    int16_t number;
    while (true)
    {
        std::cout<<"Enter number from 1 till 100 :";
        std::cin>>number;
        if (number<1||number>100)
        {
            std::cout << "Invaid input." << std::endl;
            continue;
        }
        return {
            portrait,color,tumbler,number
        };
       
    }
    
}

void PrintAnswer(WireColor color)
{
    if (color == WireColor::Nothing)
    {
        std::cout<<"You shouldn't touch any wire, bomb will not explode"<<std::endl;
        return;
    }
    std::cout<<"You should cut "<< wireNames[static_cast<int>(color)]<<" wire"<<std::endl;
}

int main()
{
    //PrintAnswer(Check(KeyboardInput()));

    {
        WireColor color = Check({Portrait::Lenin, Color::White, true, 11});
        assert(color == WireColor::Nothing);
        PrintAnswer(color);
    }

    {
        WireColor color = Check({Portrait::Ghitler, Color::Red, false, 44});
        assert(color == WireColor::Red);
        PrintAnswer(color);
    }

    {
        WireColor color = Check({Portrait::Jeorge_Washington, Color::Blue, false, 80});
        assert(color == WireColor::Red);
        PrintAnswer(color);
    }
    {
        WireColor color = Check({Portrait::Ghitler, Color::White, true, 8});
        assert(color == WireColor::Yellow);
        PrintAnswer(color);
    }
    {
        WireColor color = Check({Portrait::Ghitler, Color::Red, true, 12});
        assert(color == WireColor::Red);
        PrintAnswer(color);
    }
    {
        WireColor color = Check({Portrait::Ghitler, Color::Red, true, 8});
        assert(color == WireColor::Yellow);
        PrintAnswer(color);
    }
    {
        WireColor color = Check({Portrait::Ghitler, Color::Red, true, 4});
        assert(color == WireColor::Red);
        PrintAnswer(color);
    }
    {
        WireColor color = Check({Portrait::Ghitler, Color::Red, true, 0});
        assert(color == WireColor::Green);
        PrintAnswer(color);
    }
    {
        WireColor color = Check({Portrait::Ghitler, Color::Red, false, 11});
        assert(color == WireColor::Green);
        PrintAnswer(color);
    }
}

