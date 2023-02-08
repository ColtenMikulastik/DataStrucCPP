#include <iostream>

// global things
const int MAT_WID{ 3 };
const int MAT_HEI{ 3 };
// lets talk about matrix definitions c++ :^| 
//this is the important matrix
bool two_d_mat[MAT_HEI][MAT_WID] =
{
	{1, 1, 1},
	{0, 1, 1},
	{1, 1, 1}
};

// create 2d array that has all index's 0'd
bool checked_indexs[MAT_HEI][MAT_WID] = {};


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
		}
		if (rec_search(x - 1, y))
		{
			std::cout << "matrix at node [" << x << "][" << y << "]: and node [" << x - 1 << "][" << y << "]: are connected" << std::endl;
		}
		if (rec_search(x, y + 1))
		{
			std::cout << "matrix at node [" << x << "][" << y << "]: and node [" << x << "][" << y + 1 << "]: are connected" << std::endl;
		}
		if (rec_search(x, y - 1))
		{
			std::cout << "matrix at node [" << x << "][" << y << "]: and node [" << x << "][" << y - 1 << "]: are connected" << std::endl;
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
}
