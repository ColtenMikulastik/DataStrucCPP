
#include <iostream>

void looping(int num)
{
	for(int i{num}; i >= 0; i--)
	{
		if(i == 0) std::cout << "Done!" << std::endl;
		else std::cout << i << std::endl;
	}
}

int main()
{
	int test1 {}, test2{}, lol{};
	std::cout << "test" << std::endl;
	std::cin >> test1;
	looping(test1);
	std::cout << test1 << test2 << lol << std::endl;

	return 0;
}
