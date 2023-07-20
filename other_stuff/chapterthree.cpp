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

    std::cout << rsugar << rbutter << rflower << std::endl;

}


int main()
{
    // rectangle();
    std::cout << mypower(12, 4) << std::endl;

    ingadj();
    return 0;
}
