#include <iostream>
#include <vector>

// I am creating most thigns as global to work with the recursive function
// global things
const int MAT_WID{ 12 };
const int MAT_HEI{ 12 };

// lets talk about matrix definitions c++ :^| 
// this is the important matrix
bool two_d_mat[MAT_HEI][MAT_WID] =
{
	{1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
	{0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0},
	{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1}

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



/* The idea for the blob is that it takes the matrix index, and creates a sub-matrix.
 * The blob then uses taht infomration to either redraw sub-matrix or add conntents to it's member variables.
 * If the blob is bad, then the blob should then refactor the contents untill an acceptable matrix is found
 */

class Blob
{
private:
	static std::vector <int[2]> all_held_index;
	std::vector <int[2]> held_index;

public:
	Blob(int x, int y)
	{
		// check this index given
		if (two_d_mat[x][y] == 1)
		{
			// add index to teh thing....
			this->all_held_index.push_back({ x, y });
			this->held_index.push_back({ x, y });
		}
		else
		{
			// early return
		}
		
		// check that index is a 1
		bool zero_found_x{ 0 }, zero_found_y{ 0 };

		while (!zero_found_x && !zero_found_y)
		{
			std::cout << "oh yay!" << std::endl;

		}



	}
	
};


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
			// add information to the adjacency matrix, add to both sides of the adj_mat
			std::cout << "matrix at node [" << x << "][" << y << "]: and node [" << x << "][" << y + 1 << "]: are connected" << std::endl;
			adj_mat[(x * MAT_HEI) + y][(x * MAT_HEI) + (y + 1)] = 1;
			// unsure of why this is bufferoverflowing :^.
			adj_mat[(x * MAT_HEI) + (y + 1)][(x * MAT_HEI) + y] = 1;
		}
		if (rec_search(x, y - 1))
		{
			// add information to the adjacency matrix, add to both sides of the adj_mat
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

// function that finds all adjacencies in a graph
void brute_search()
{
	// loop through the whole matrix
	for (int i{}; i <= (MAT_WID - 1); i++)
	{
		for (int j{}; j <= (MAT_HEI - 1); j++)
		{
			// check index bellow current index while also checking if the indexs are in-bounds
			if(!((i + 1) >= MAT_WID) && two_d_mat[i][j] == 1 && two_d_mat[(i + 1)][j] == 1)
			{
				// add to adjacency matrix
				adj_mat[(i * MAT_HEI) + j][((i + 1) * MAT_HEI) + j] = 1;
				adj_mat[((i + 1) * MAT_HEI) + j][(i * MAT_HEI) + j] = 1;
			}
			
			// check index above current index, and in-bounds
			if(!((i - 1) <= MAT_WID) && two_d_mat[i][j] == 1 && two_d_mat[(i - 1)][j] == 1)
			{
				// add to adjacency matrix
				adj_mat[(i * MAT_HEI) + j][((i - 1) * MAT_HEI) + j] = 1;
				adj_mat[((i - 1) * MAT_HEI) + j][(i * MAT_HEI) + j] = 1;
			}

			// check index to the righ of index, and in-bounds
			if(!((j + 1) >= MAT_HEI) && two_d_mat[i][j] == 1 && two_d_mat[i][(j + 1)] == 1)
			{
				// add to adjacency matrix
				adj_mat[(i * MAT_HEI) + j][(i * MAT_HEI) + (j + 1)] = 1;
				adj_mat[(i * MAT_HEI) + (j + 1)][(i * MAT_HEI) + j] = 1;
			}

			// check index left of index, and in-bounds
			if(!((j - 1) <= MAT_HEI) && two_d_mat[i][j] == 1 && two_d_mat[i][(j - 1)] == 1)
			{
				// add to adjacency matrix
				adj_mat[(i * MAT_HEI) + j][(i * MAT_HEI) + (j - 1)] = 1;
				adj_mat[(i * MAT_HEI) + (j - 1)][(i * MAT_HEI) + j] = 1;
			}
		}
	}

}


int main()
{
	std::cout << "----------------PRINTING OG MATRIX----------------" << std::endl;
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
	brute_search();


	std::cout << "----------------CHECKED INDEX MATRIX----------------" << std::endl;
	// print the checked_index matrix
	for (int i{}; i <= (MAT_WID - 1); i++)
	{
		for (int j{}; j <= (MAT_HEI - 1); j++)
		{
			std::cout << checked_indexs[i][j] << ", ";
		}
		std::cout << std::endl;
	}
	
	std::cout << "----------------PRINTING ADJACENCY MATRIX----------------" << std::endl;
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


	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "----------------PRINTING CONNECTIVITY MATRIX----------------" << std::endl;
	// print connections right?
	for (int i{}; i <= (MAT_WID - 1); i++)
	{
		for (int j{}; j <= (MAT_HEI - 1); j++)
		{
			// if connected horizontally
			if (adj_mat[(i * MAT_WID) + j][(i * MAT_WID) + (j + 1)] == 1)
			{
				std::cout << two_d_mat[i][j] << "-";
			}
			else
			{
				std::cout << two_d_mat[i][j] << " ";
			}
		}
		std::cout << std::endl;

		for (int k{}; k <= (MAT_WID - 1); k++)
		{
			// if connected horizontally
			if (adj_mat[(i * MAT_WID) + k][((i + 1) * MAT_WID ) + k])
			{
				std::cout << "| ";
			}
			else
			{
				std::cout << "  ";
			}
		}
		std::cout << std::endl;
	}
}
