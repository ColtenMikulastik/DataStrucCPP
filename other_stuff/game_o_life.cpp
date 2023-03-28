#include <iostream>

void print_mat();
char print_interface();


const int MAT_WID = {3};
const int MAT_HEI = {3};

bool bin_mat[MAT_WID][MAT_HEI]= 
{
	{0,0,0},
	{1,1,1},
	{0,0,0}
};


char print_interface()
{
	char inp {};
	std::cout << "Hello! and Welcome to my virsion on Conway's game of life!" << std::endl;
	std::cout << "<press 'y' and enter to begin!>" << std::endl;
	std::cin >> inp;
	std::cout << "okay, come back soon!" << std::endl;
	return inp;

}

void print_mat()
{
	for(int i{}; i <= (MAT_HEI - 1); i++)
	{
		for(int j{}; j <= (MAT_WID - 1); j++)
		{
			std::cout << bin_mat[i][j];
		}
		std::cout << std::endl;
	}

}

int main()
{

	print_interface();
	print_mat();

	char stop {};
	std::cin >> stop;

}


