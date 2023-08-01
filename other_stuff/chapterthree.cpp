#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

int mypower(int num, int pow)
{
    int result{num};

    while(pow > 1)
    {
        result = result * num;
        pow--;
    }

    return result;
}


void rectangle()
{
    // this program takes user input and calculates the area of a rectangle
    int length{}, width{};
    std::cout << "let's calculate the area of a triangle" << std::endl;
    std::cout << "length: ";
    std::cin >> length;
    std::cout << "width: ";
    std::cin >> width;
    std::cout << "your triangle is: " << (length * width) << " units squared!" << std::endl;

}


void ingadj()
{
	/*
     * recipy: 1.5 cups of sugar, 1 cup butter, and 2.75 cup flower
     *
     */

    const double rsugar{1.5}, rbutter{1}, rflower{2.75};

    double input{};

    // grab input
    std::cout << "how many cookies do you want to make?: ";
    std::cin >> input;

    // get ratio of input and of default cookies
    double ratio = input / 48;

    std::cout << "to make " << input << " cookies you will need:" << std::endl;
    std::cout << rsugar * ratio << " cups of sugar" << std::endl;
    std::cout << rbutter * ratio << " cups of butter" << std::endl;
    std::cout << rflower * ratio << " cups of flower" << std::endl; 
}

void mathtutor()
{
	// doing the random stuffs
	unsigned seed = time(0);
	srand(seed);
	
	// generate the numbers
	int firstnumber = (rand() % 1001), secondnumber = (rand() % 1001);
	
	int trash{};
	std::cout << " " << firstnumber << std::endl;
	std::cout << "+" << secondnumber << std::endl;
	std::cout << "--------" << std::endl;
	std::cin >> trash;
	std::cout << firstnumber + secondnumber << std::endl;
}

void interest_earned()
{
    // amount = principal * ( 1 + (rate/T))^T
    // T = time
    
    double int_rate{}, time{}, principal{}, interest{};
    
    // get input
    std::cout << "please give your interest rate (in percent): ";
    std::cin >> int_rate;
    int_rate = int_rate / 100;
    std::cout << "please give the time in cycles: ";
    std::cin >> time;
    std::cout << "please give the principal: ";
    std::cin >> principal;

    interest = pow(1 + (int_rate/time), time);
    std::cout << "your interest will be: " << (principal * interest) - principal << std::endl;

    std::cout << "your final ammount will be " << principal * interest << std::endl;
}


void retail_sale()
{

	double total_sale {};
	std::cout << "What is the total today?: ";
	std::cin >> total_sale;

	std::cout << total_sale << "$" << std::endl;

}


int main()
{
    // rectangle();
    std::cout << mypower(12, 4) << std::endl;

    retail_sale();
    return 0;
}
