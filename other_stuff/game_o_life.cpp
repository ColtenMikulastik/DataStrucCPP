#include <iostream>


// function prototypes
void print_mat();
char print_interface();
void mgmt_mats();
void update_adj_matrix();


// define and assign global variables values
const int MAT_WID = {3};
const int MAT_HEI = {3};

bool bin_mat[MAT_WID][MAT_HEI]= 
{
	{0,0,0},
	{1,1,1},
	{0,0,0}
};

bool adj_mat[MAT_WID * 2][MAT_HEI * 2]={};


// function definitions
void update_adj_matrix()
{
	// loop through the whole matrix
	
	
}

char print_interface()
{
	// print the interface n' stuff
	char inp {};
	std::cout << "Hello! and Welcome to my virsion on Conway's game of life!" << std::endl;
	std::cout << "<press 'y' and enter to begin!>" << std::endl;
	std::cin >> inp;
	std::cout << "okay, come back soon!" << std::endl;
	return inp;
}

void print_mat()
{
	//print the matrix
	
	for(int i{}; i <= (MAT_HEI - 1); i++)
	{
		for(int j{}; j <= (MAT_WID - 1); j++)
		{
			std::cout << bin_mat[i][j];
		}
		std::cout << std::endl;
	}
}

void mgmt_mats()
{	
	// print the matric with function
	print_mat();
	
	// print the adj matrix
	for(int i{}; i <= ((MAT_HEI * 2) - 1); i++)
	{
		for(int j{}; j <= ((MAT_WID * 2) - 1); j++)
		{
			std::cout << adj_mat[i][j];
		}
		std::cout << std::endl;
	}
}

int main()
{
	print_interface();
	print_mat();
	
	
	mgmt_mats();
	char stop {};
	std::cin >> stop;
}

