#include <iostream>

bool is_uppercase(char test)
{
    // we can tell the case of a letter by utilizing the int ascii value of a char
    
    std::cout << "Your character is: " << test << std::endl;
    
    // run cout depending on value of test
    if ((test >= 65) && (test <= 90))
    {
        // test is a uppercase letter
        std::cout << test << " is uppercase" << std::endl;
        return 1;
    }
    else if ((test >= 97) && (test <= 122))
    {
        //test will be a lower case letter
        std::cout << test << " is lowercase" << std::endl;
        return 0;
    }
    else
    {
        //test is some unknown value
        std::cout << test << " is unknown" << std::endl;
        return 0;
    }
}

void progfourone()
{
	bool trueV{}, falseV{};
	int x = 5, y = 10;
	
	trueV = x < y;
	falseV = y == x;

	std::cout << "True is " << trueV << std::endl;
	std::cout << "False is " << falseV << std::endl;
}


int main()
{
    std::cout << is_uppercase('a') << std::endl;
    std::cout << is_uppercase('A') << std::endl;
}
