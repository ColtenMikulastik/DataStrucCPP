#include <iostream>

/* Colten (Luca) Vance Mikulastik
 * Reviewing c++ stuff, and some programs to help me remember
 *
 */


// these are interesting functions that I made up

void how_many_bits(int range_start, int range_end)
{
	// if you give the function a range it will tell you how many bytes you will need to store it
	if(range_start > 0)
	{
		std::cout << "your data type is signed" << std::endl;
		// because it's signed the data type can be just two times the original end value to zero
		range_start = 0;
		range_end = range_end * 2;
	}
	

	// half the number and add a bit
	int num_of_bits{};
	while( range_end >= 1 )
	{
		range_end /= 2;
		num_of_bits++;
	}

	std::cout << "this data type is stored with :" << num_of_bits << " bits" << std::endl;
}



//interesting projects from the book c++ from control structures through objects Chapter 2

double miles_per_gallon(int gallons, int miles)
{
	// A car holds 15 gallons of gasoline and can travel 375 miles before refueling.
	// MPG = miles driven/ Gallon of Gas Used
	double mpg = (miles / gallons);
	
	//print var
	std::cout << mpg << std::endl;
	return mpg;	 
}


void print_triangle()
{

}


int main()
{
	miles_per_gallon(15, 375);
	

	// a short int is 2 bytes and has a range of -32,768 to 32,767
	// unsigned has 65,535 same ammount of bytes
	short int foo {};
	std::cout << "The Size of foo is: " << sizeof(foo) << " bytes." << std::endl;
	how_many_bits(65535);
	


}
