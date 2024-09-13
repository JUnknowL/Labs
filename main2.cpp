#include <iostream>
using namespace std;

namespace TestName
{
	int cout = 0;
	void logic()
	{
		std::cout<<'\n';
		std::cout<<"Input numbers of hello worlds:";
		cin >> i;
		for (int j = 0;j<i;j++)
		{
			std::cout<<"Hello world\n";
		}
	}
}
int main()
	{
		TestName::logic();
		return 0;
	}
	
