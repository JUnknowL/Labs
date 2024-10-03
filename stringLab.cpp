#include <iostream>
#include <cassert>

//ОбЪявлена в двух местах но нигде не определена
size_t count1(const char*,size_t);
std::string_view SecondWorld(std::string_view);

int main()  
{
    std::string_view test = "somethingel  test";

    std::cout<<SecondWorld(test)<<'\n';

    std::cout<<"Finish";



    return 0;
}

size_t count1(std::string_view string)
{
    size_t count1 = 0;
    for (size_t i = 0;i<string.length();i++)
    {
        if (string[i]=='1') count1++;
    }
    return count1;
}

size_t FindSpace(std::string_view string)
{
    for (size_t i = 0; i < string.length();i++)
    {
        if (string[i]==' ') return i;
    }
    return string.length();
}

std::string_view SecondWorld(std::string_view string)
{
    size_t start = FindSpace(string);
    if (start == string.length()) return "";
    start++;
    std::string_view substring = string.substr(start);
    size_t finish = FindSpace(substring);
    return { substring.data(), finish };    // return substring.substr(0,finish);
}

