#include <iostream>


// function prototypes
void print_mat();
char print_interface();
void mgmt_mats();
void update_adj_matrix();


// define and assign global variables values
const int MAT_WID = {3};
const int MAT_HEI = {3};

// strainge this one first node is hitting third node for some reason, gonna have to check this out
bool bin_mat[MAT_WID][MAT_HEI]= 
{
	{1,0,1},
	{0,1,0},
	{0,0,0}
};

bool adj_mat[MAT_WID * MAT_HEI][MAT_WID * MAT_HEI]={};


// function definitions
void update_adj_matrix()
{
	// loop through the whole matrix
	for(int i{}; i <= (MAT_WID - 1); i++)
	{
		for(int j{}; j <= (MAT_HEI - 1); j++)
		{
			// check index arround current index and then adjust adj mat as necissary
			if(!((i + 1) >= MAT_WID) && bin_mat[i][j] == 1 && bin_mat[(i + 1)][j] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][((i + 1) * MAT_HEI) + j] = 1;
				adj_mat[((i + 1) * MAT_HEI) + j][(i * MAT_HEI) + j] = 1;
				
				// nested diagonals
				if(!((j + 1) >= MAT_HEI) && bin_mat[i][j] == 1 && bin_mat[(i + 1)][(j + 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i + 1) * MAT_HEI) + (j + 1)] = 1;
					adj_mat[((i + 1) * MAT_HEI) + (j + 1)][(i * MAT_HEI) + j] = 1;
				}
				if(!((j - 1) >= MAT_HEI) && bin_mat[i][j] == 1 && bin_mat[(i + 1)][(j - 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i + 1) * MAT_HEI) + (j - 1)] = 1;
					adj_mat[((i + 1) * MAT_HEI) + (j - 1)][(i * MAT_HEI) + j] = 1;
				}
			}
			if(!((i - 1) <= MAT_WID) && bin_mat[i][j] == 1 && bin_mat[(i - 1)][j] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][((i - 1) * MAT_HEI) + j] = 1;
				adj_mat[((i - 1) * MAT_HEI) + j][(i * MAT_HEI) + j] = 1;
				
				// nested diagonals
				if(!((j + 1) >= MAT_HEI) && bin_mat[i][j] == 1 && bin_mat[(i - 1)][(j + 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i - 1) * MAT_HEI) + (j + 1)] = 1;
					adj_mat[((i - 1) * MAT_HEI) + (j + 1)][(i * MAT_HEI) + j] = 1;
				}
				if(!((j - 1) >= MAT_HEI) && bin_mat[i][j] == 1 && bin_mat[(i - 1)][(j - 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i - 1) * MAT_HEI) + (j - 1)] = 1;
					adj_mat[((i - 1) * MAT_HEI) + (j - 1)][(i * MAT_HEI) + j] = 1;
				}
			}
			if(!((j + 1) >= MAT_HEI) && bin_mat[i][j] == 1 && bin_mat[i][(j + 1)] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][(i * MAT_HEI) + (j + 1)] = 1;
				adj_mat[(i * MAT_HEI) + (j + 1)][(i * MAT_HEI) + j] = 1;
			}
			if(!((j - 1) <= MAT_HEI) && bin_mat[i][j] == 1 && bin_mat[i][(j - 1)] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][(i * MAT_HEI) + (j - 1)] = 1;
				adj_mat[(i * MAT_HEI) + (j - 1)][(i * MAT_HEI) + j] = 1;
			}
			
			// I have checked the cardinal directions-amin 
			// so I also need to log adj to diagonals
		}
	}
	
	
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
	for(int i{}; i <= ((MAT_HEI * MAT_WID) - 1); i++)
	{
		for(int j{}; j <= ((MAT_HEI * MAT_WID) - 1); j++)
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
	update_adj_matrix();
	mgmt_mats();
	char stop {};
	std::cin >> stop;
}


