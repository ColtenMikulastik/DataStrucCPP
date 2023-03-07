#include <iostream>
#include "ByteStruc/ByteStruc.cpp"

int main()
{
    char input {};
    while (input != 'q')
    {
	std::cout << "please press enter or 'q' to quit: ";
	std::cin >> input;

	if( input == 'q' )
	{
		std::cout << "okay quitting!" << std::endl;
	}
	else
	{
		int num {};
		std::cout << "please give me a number: ";
		std::cin >> num;
		ByteStruc byte(num);
		std::cout << "thing:" << byte.get_bit_at(3) << std::endl;
		byte.print_byte();
	}
    }
} 
