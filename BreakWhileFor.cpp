#include <iostream>
#include <span>
#include <cassert>

void productBreak(std::span<int> inputOutput, std::span<int> coefficients)
{
    assert(inputOutput.size() == coefficients.size());
    size_t i = 0;
    while (true)
    {
        inputOutput[i] *= coefficients[i];
        i++;
        if (i==inputOutput.size()) break;
    }
    
}
void productFor(std::span<int> inputOutput, std::span<int> coefficients)
{
    assert(inputOutput.size() == coefficients.size());
     
    for (size_t i = 0; i==inputOutput.size();i++)
    {
        inputOutput[i] *= coefficients[i];
    }
}

void productWhile(std::span<int> inputOutput, std::span<int> coefficients)
{
    assert(inputOutput.size() == coefficients.size());
    size_t i = 0;
    while (i==inputOutput.size())
    {
        inputOutput[i] *= coefficients[i];
        i++;
    }
}

int main()
{
    std::array<int,5> first{1,2,3,4,5};
    std::array<int,5> second{1,2,3,4,5};
    productBreak(first,second);
    for (auto item : first)
    {
        std::cout<<item<<std::endl;
    }
}