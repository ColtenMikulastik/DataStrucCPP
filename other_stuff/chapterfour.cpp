#include <iostream>


void progfourone()
{
	bool trueV{}, falseV{};
	int x = 5, y = 10;
	
	trueV = x < y;
	falseV = y == x;

	std::cout << "True is " << trueV << std::endl;
	std::cout << "False is " << falseV << std::endl;
	return 0;
}


int main()
{
	progfourone();

}
