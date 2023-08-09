#include <iostream>

void menu();
void progfourone();
bool is_uppercase(char test);

void menu()
{
    char choice {};
    std::cout << "what would you like to do (a,b,c,d,e)" << std::endl;
    std::cin >> choice;
    switch(choice)
    {
        case 'a':
            {
            std::cout << "you chose a" <<std::endl;
            char letter{};
            std::cout << "please give me a letter: ";
            std::cin >> letter;
            is_uppercase(letter);
            break;
            }

        case 'b':
            std::cout << "you chose b" <<std::endl;
                break;

        case 'c':
            std::cout << "you chose c" <<std::endl;
                break;

        case 'd':
            std::cout << "you chose d" <<std::endl;
                break;

        case 'e':
            std::cout << "you chose e" <<std::endl;
                break;

        default:
            std::cout << "hmmm you didn't do it right" << std::endl;

    }
}


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
    menu();
    std::cout << is_uppercase('a') << std::endl;
    std::cout << is_uppercase('A') << std::endl;
}
