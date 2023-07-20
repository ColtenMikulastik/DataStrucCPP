#include <iostream>

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


int main()
{
    // rectangle();
    std::cout << mypower(12, 4) << std::endl;

    ingadj();
    return 0;
}
