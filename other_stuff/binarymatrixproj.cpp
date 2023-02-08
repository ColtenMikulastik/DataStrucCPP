#include <iostream>

// I am creating most thigns as global to work with the recursive function
// global things
const int MAT_WID{ 6 };
const int MAT_HEI{ 6 };

// lets talk about matrix definitions c++ :^| 
// this is the important matrix
bool two_d_mat[MAT_HEI][MAT_WID] =
{
	{1, 0, 1, 1, 1, 0},
	{1, 1, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 1},
	{0, 1, 1, 1, 0, 0}
};

// create 2d array that has all index's 0'd
bool checked_indexs[MAT_HEI][MAT_WID] = {};

// I wonder if I can make a adjacent matrix
// create a 2-d matrix, wid and height are going to be = MAT_WID * MAT_HIE
bool adj_mat[MAT_WID * MAT_HEI][MAT_WID * MAT_HEI] = {};

/*
adjacency matrixing

in mat:
1, 0, 1,
1, 1, 1,
0, 0, 0

result after giving each index a node name ex: (a, b, c,) (d, e, f,) (g, h, i,)
{
  a b c d e f g h i
a 0 0 0 1 0 0 0 0 0
b 0 0 0 0 0 0 0 0 0
c 0 0 0 0 0 1 0 0 0
d 1 0 0 0 1 0 0 0 0
e 0 0 0 1 0 1 0 0 0
f 0 0 1 0 1 0 0 0 0
g 0 0 0 0 0 0 0 0 0
h 0 0 0 0 0 0 0 0 0
i 0 0 0 0 0 0 0 0 0
}
*/


// recursive function to search matrix
bool rec_search(int x, int y)
{
	// look for 1's that aren't out of bounds and haven't been seen yet
	if (two_d_mat[x][y] == 1 && x < MAT_HEI && y < MAT_WID && x >= 0 && y >= 0 && (checked_indexs[x][y] == 0))
	{
		// add index to found index
		checked_indexs[x][y] = 1;

		// check indexs all around the current index
		if (rec_search(x + 1, y))
		{
			std::cout << "matrix at node [" << x << "][" << y << "]: and node [" << x + 1 << "][" << y << "]: are connected" << std::endl;
			// add information to the adjacency matrix, add to both sides of the adj_mat
			// so if I want to skip down a x value, I can mulitply the x value by MAT_HEI, then add the y value
			adj_mat[(x * MAT_HEI) + y][((x + 1) * MAT_HEI) + y] = 1;
			adj_mat[((x + 1) * MAT_HEI) + y][(x * MAT_HEI) + y] = 1;
		}
		if (rec_search(x - 1, y))
		{
			std::cout << "matrix at node [" << x << "][" << y << "]: and node [" << x - 1 << "][" << y << "]: are connected" << std::endl;
			// add information to the adjacency matrix, add to both sides of the adj_mat
			adj_mat[(x * MAT_HEI) + y][((x - 1) * MAT_HEI) + y] = 1;
			adj_mat[((x - 1) * MAT_HEI) + y][(x * MAT_HEI) + y] = 1;
		}
		if (rec_search(x, y + 1))
		{
			std::cout << "matrix at node [" << x << "][" << y << "]: and node [" << x << "][" << y + 1 << "]: are connected" << std::endl;
			adj_mat[(x * MAT_HEI) + y][(x * MAT_HEI) + (y + 1)] = 1;
			adj_mat[(x * MAT_HEI) + (y + 1)][(x * MAT_HEI) + y] = 1;
		}
		if (rec_search(x, y - 1))
		{
			std::cout << "matrix at node [" << x << "][" << y << "]: and node [" << x << "][" << y - 1 << "]: are connected" << std::endl;
			adj_mat[(x * MAT_HEI) + y][(x * MAT_HEI) + (y - 1)] = 1;
			adj_mat[(x * MAT_HEI) + (y - 1)][(x * MAT_HEI) + y] = 1;
		}

		// once all have been checked, then return 1	
		return 1;	
		
	}
	else 
		return 0;
}


int main()
{
	
	// print the 2d-matrix
	for (int i{}; i <= (MAT_WID - 1); i++)
	{
		for (int j{}; j <= (MAT_HEI - 1); j++)
		{
			std::cout << two_d_mat[i][j] << ", ";
		}
		std::cout << std::endl;
	}
	
	/*
	I'm going to make a recusive function...
	It will look for a 1,
	once found, then it will call itself again and look for one's in surrounding blocks
	then if found again, then see above
	function terminates when it finds 0 or 1 that has already been seen
	damn this is hard lmao
	*/

	//call function
	rec_search(0, 0);

	// print the checked_index matrix
	for (int i{}; i <= (MAT_WID - 1); i++)
	{
		for (int j{}; j <= (MAT_HEI - 1); j++)
		{
			std::cout << checked_indexs[i][j] << ", ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "----------------UNDER CONSTRUCTION----------------" << std::endl;
	// print nodes
	for (int i{}; i <= (MAT_WID - 1); i++)
	{
		for (int j{}; j <= (MAT_HEI - 1); j++)
			std::cout << two_d_mat[i][j] << ", ";
	}
	
	std::cout << ": " << std::endl;
	std::cout << "-----------------------------------------" << std::endl;

	// print the adjacency matrix
	for (int i{}; i <= ((MAT_WID * MAT_HEI) - 1); i++)
	{
		
		for (int j{}; j <= ((MAT_HEI * MAT_WID) - 1); j++)
		{
			std::cout << adj_mat[i][j] << ", ";
		}
		std::cout << std::endl;
	}


}
