#include <iostream>



//interesting projects from the book c++ from control structures through objects


double miles_per_gallon(int gallons, int miles)
{
	// A car holds 15 gallons of gasoline and can travel 375 miles before refueling.
	// MPG = miles driven/ Gallon of Gas Used
	double mpg = (miles / gallons);
	
	//print var
	std::cout << mpg << std::endl;
	return mpg;	 
}



int main()
{
	miles_per_gallon(15, 375);



}
