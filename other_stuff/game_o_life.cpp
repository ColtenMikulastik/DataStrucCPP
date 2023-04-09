#include <iostream>
#include <unistd.h>

// function prototypes
void print_mat();
char print_interface();
void mgmt_mats();
void update_adj_mat();
void update_mat();


// define and assign global variables values
const int MAT_WID = {3};
const int MAT_HEI = {3};

// strainge this one first node is hitting third node for some reason, gonna have to check this out
bool bin_mat[MAT_WID][MAT_HEI]= 
{
	{0,0,0},
	{1,1,1},
	{0,0,0}
};

bool adj_mat[MAT_WID * MAT_HEI][MAT_WID * MAT_HEI]={};


// function definitions:
// this function finds all connected ones in the eight cells around it
void connected_ones_update_adj_matrix()
{
	// real index values
	int real_MAT_HEI = MAT_HEI - 1;
	int real_MAT_WID = MAT_WID - 1;

	// loop through the whole matrix
	for(int i{}; i <= real_MAT_HEI; i++)
	{
		for(int j{}; j <= real_MAT_WID; j++)
		{
			// check index arround current index and then adjust adj mat as necissary
			// i has to do with height, j has to do with width
			if(((i + 1) <= real_MAT_HEI) && bin_mat[i][j] == 1 && bin_mat[(i + 1)][j] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][((i + 1) * MAT_HEI) + j] = 1;
				adj_mat[((i + 1) * MAT_HEI) + j][(i * MAT_HEI) + j] = 1;
			}
				
			// diagonals	
			if(((i + 1) <= real_MAT_HEI))
			{
				if(((j + 1) <= real_MAT_WID) && bin_mat[i][j] == 1 && bin_mat[(i + 1)][(j + 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i + 1) * MAT_HEI) + (j + 1)] = 1;
					adj_mat[((i + 1) * MAT_HEI) + (j + 1)][(i * MAT_HEI) + j] = 1;
				}
				if(((j - 1) >= 0) && bin_mat[i][j] == 1 && bin_mat[(i + 1)][(j - 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i + 1) * MAT_HEI) + (j - 1)] = 1;
					adj_mat[((i + 1) * MAT_HEI) + (j - 1)][(i * MAT_HEI) + j] = 1;
				}
			}

			// down index
			if(((i - 1) >= 0) && bin_mat[i][j] == 1 && bin_mat[(i - 1)][j] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][((i - 1) * MAT_HEI) + j] = 1;
				adj_mat[((i - 1) * MAT_HEI) + j][(i * MAT_HEI) + j] = 1;
			}
			
			// diagonals
			if(((i - 1) >= 0))
			{
				if(((j + 1) <= real_MAT_HEI) && bin_mat[i][j] == 1 && bin_mat[(i - 1)][(j + 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i - 1) * MAT_HEI) + (j + 1)] = 1;
					adj_mat[((i - 1) * MAT_HEI) + (j + 1)][(i * MAT_HEI) + j] = 1;
				}
				if(((j - 1) >= 0) && bin_mat[i][j] == 1 && bin_mat[(i - 1)][(j - 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i - 1) * MAT_HEI) + (j - 1)] = 1;
					adj_mat[((i - 1) * MAT_HEI) + (j - 1)][(i * MAT_HEI) + j] = 1;
				}
			}
			
			// left and right
			if(((j + 1) <= real_MAT_WID) && bin_mat[i][j] == 1 && bin_mat[i][(j + 1)] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][(i * MAT_HEI) + (j + 1)] = 1;
				adj_mat[(i * MAT_HEI) + (j + 1)][(i * MAT_HEI) + j] = 1;
			}
			if(((j - 1) >= 0) && bin_mat[i][j] == 1 && bin_mat[i][(j - 1)] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][(i * MAT_HEI) + (j - 1)] = 1;
				adj_mat[(i * MAT_HEI) + (j - 1)][(i * MAT_HEI) + j] = 1;
			}
			
		}
	}
	
}

// this function will log all connections to ones, even in dead cells, which is required for conway's game of life
// removing addtions to the adj to one of hte sides 
// maybe we should only be logging the eight adjacencys...
void update_adj_mat()
{
	
	// reset the adj matrix duh!
	for(int i{}; i <= (MAT_HEI * MAT_WID); i++)
	{
		for(int j{}; j <= (MAT_HEI * MAT_WID); j++)
		{
			adj_mat[i][j] = 0;
		}
	}

	// real index values
	int real_MAT_HEI = MAT_HEI - 1;
	int real_MAT_WID = MAT_WID - 1;

	// loop through the whole matrix
	for(int i{}; i <= real_MAT_HEI; i++)
	{
		for(int j{}; j <= real_MAT_WID; j++)
		{
			// check index arround current index and then adjust adj mat as necissary
			// i has to do with height, j has to do with width
			if(((i + 1) <= real_MAT_HEI) && bin_mat[(i + 1)][j] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][((i + 1) * MAT_HEI) + j] = 1;
			}
				
			// diagonals	
			if(((i + 1) <= real_MAT_HEI))
			{
				if(((j + 1) <= real_MAT_WID) && bin_mat[(i + 1)][(j + 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i + 1) * MAT_HEI) + (j + 1)] = 1;
				}
				if(((j - 1) >= 0) && bin_mat[(i + 1)][(j - 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i + 1) * MAT_HEI) + (j - 1)] = 1;
				}
			}

			// down index
			if(((i - 1) >= 0) && bin_mat[(i - 1)][j] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][((i - 1) * MAT_HEI) + j] = 1;
			}
			
			// diagonals
			if(((i - 1) >= 0))
			{
				if(((j + 1) <= real_MAT_HEI) && bin_mat[(i - 1)][(j + 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i - 1) * MAT_HEI) + (j + 1)] = 1;
				}
				if(((j - 1) >= 0) && bin_mat[(i - 1)][(j - 1)] == 1)
				{
					adj_mat[(i * MAT_HEI) + j][((i - 1) * MAT_HEI) + (j - 1)] = 1;
				}
			}
			
			// left and right
			if(((j + 1) <= real_MAT_WID) && bin_mat[i][(j + 1)] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][(i * MAT_HEI) + (j + 1)] = 1;
			}
			if(((j - 1) >= 0) && bin_mat[i][(j - 1)] == 1)
			{
				adj_mat[(i * MAT_HEI) + j][(i * MAT_HEI) + (j - 1)] = 1;
			}
			
		}
	}
	
}

void update_mat()
{
	
	// create new matrix
	bool new_bin_mat[MAT_WID][MAT_HEI]={};
	
	// loop trough matrix
	for(int i{}; i <= (MAT_HEI - 1); i++)
	{
		for(int j{}; j <= (MAT_WID - 1); j++)
		{

			// tally live adj cells
			int total_live_cells={};
			for( int a{}; a <= ((MAT_HEI * MAT_WID) - 1); a++)
			{
				total_live_cells = total_live_cells + adj_mat[(i * MAT_HEI) + j][a];
			}
			
			// populate new matrix based on the tally, and the conways rules
			if( bin_mat[i][j] == 1 && (total_live_cells == 2 || total_live_cells == 3))
			{
				//living cell with 2 or 3 neighbors lives
				new_bin_mat[i][j] = 1;
			}
			else if( bin_mat[i][j] == 0 && total_live_cells == 3)
			{
				// dead cell with 3 neighbors lives
				new_bin_mat[i][j] = 1;
			}
			else
			{
				// all other die or stay dead
				new_bin_mat[i][j] = 0;
			}
		}
	}
	
	// then loop through both matrix and load information into old-new matrix
	
	for(int i{}; i <= (MAT_HEI - 1); i++)
	{
		for(int j{}; j <= (MAT_WID - 1); j++)
		{
			bin_mat[i][j] = new_bin_mat[i][j];
		}
	}
}

char print_interface()
{
	// print the interface n' stuff
	char inp {};
	std::cout << "Hello! and Welcome to my version on Conway's game of life!" << std::endl;
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
	// print the matrix with function
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
	
	while(1)
	{
		// just so we don't print it too much
		std::cout << "--------------------------" << std::endl;
		usleep(1000000);
		print_mat();
		update_adj_mat();
		update_mat();
	}

	char stop {};
	std::cin >> stop;
}


