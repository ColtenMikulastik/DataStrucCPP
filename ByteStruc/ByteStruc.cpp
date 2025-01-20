#include <bits/fs_fwd.h>
#include <iostream>
#include <cmath>

class ByteStruc
{
private:
	bool *byte;
public:
	static void num_to_byte(int in_num, bool *returnable);
	static void make_twos_comp_neg(bool *returnable);
	ByteStruc(int temp_int);
	ByteStruc(ByteStruc &input);
	void print_byte();
	bool get_bit_at(int index);
	void add_bytes( ByteStruc right );
	int byte_to_int();
	~ByteStruc();
};

// num to byte func
void ByteStruc::num_to_byte(int in_num, bool *returnable)
{

	// check for extranius values
	if ((in_num >= 255) || (in_num <= 0))
	{
		// tell user what happend and let fall to trailing nullptr
		std::cout << "number too large or small, sorry :^(" << std::endl;
	}
	else 
	{
		// create iterable, and difference
		int i{ 7 };
		int dif{ 128 };

		// loop til' end of array :^)
		while (i >= 0)
		{
			if (in_num >= dif)
			{
				returnable[i] = 1;
				in_num -= dif;
			}
			else
			{
				returnable[i] = 0;
			}
			dif /= 2;
			i--;
		}
	}
	returnable = nullptr;
}

// creates a twos-complement byte
void ByteStruc::make_twos_comp_neg(bool *returnable)
{
	// this should fill out the byte with the last bit being a positive or negative flag
	// ^ this desicribes sign and magnitude, not twos comp
	
	// flip all the bits
	for(int i{}; i <= 7; i++)
	{
		returnable[i] = !returnable[i];
	}
	// add a 1
	// wow this has defeated me
	// this is sillyness
}

ByteStruc::ByteStruc(int temp_int)
{
	//make new bool array on heap
	this->byte = new bool[8];

	// send the int and bool array to the num_to_byte function
	num_to_byte(temp_int, this->byte);

	std::cout << "completed Byte contstruction" << std::endl;
}

// copy constructor: because I forgot about this lel
ByteStruc::ByteStruc(ByteStruc &input)
{
	// create another byte on teh heap
	this->byte = new bool[8];

	// loop through the new byte and deep copy data
	for(int i{}; i <= 7; i++)
	{	
		this->byte[i] = input.get_bit_at(i);
	}

	std::cout << "copy construc: completed Byte Construction" << std::endl;
}

void ByteStruc::print_byte()
{
	std::cout << "printing byte:" << std::endl;
	for (int i{0}; i <= 7; i++)
	{
		std::cout << "byte at [" << i << "]: " << this->byte[i] << std::endl;
	}
}

bool ByteStruc::get_bit_at(int index)
{
	// get bit at a specific index
	return this->byte[index];
}

void ByteStruc::add_bytes( ByteStruc right )
{
	// this adds this byte with another byte (gonna be the non-"twos complement" bytes)
	// right now this will just print the output
	// print what's happening 
	std::cout << "adding two bytes: " << std::endl;
	this->print_byte();
	right.print_byte();
	std::cout << "sum: " << std::endl;
	
	bool carry {};
	// loop through all the indexies
	for( int i{0}; i <= 7; i++)
	{
		bool right_bit = right.get_bit_at(i);
		bool left_bit = this->get_bit_at(i);

		if( (right_bit == 1 && left_bit == 1 )||(carry == 1 && (left_bit == 1 || right_bit == 1)))
		{
			if( left_bit == 1 && right_bit == 1 && carry == 1)
			{
				// if all of them are one
				std::cout << "index [" << i << "] is: 1" << std::endl;
			}	
			else
			{
				// if just two of them are 1
				std::cout << "index [" << i << "] is: 0" << std::endl;
			}
			// hanging carry 
			carry = 1;
		}
		else if( right_bit == 1 || left_bit == 1 || carry == 1)
		{
			std::cout << "index [" << i << "] is: 1" << std::endl;
			carry = 0;
		}
		else
		{
			std::cout << "index [" << i << "] is: 0" << std::endl;
		}	
	}
}

int ByteStruc::byte_to_int()
{
	int sum {};
	// this function will take the bit place values and multiply them by their decimal values
	for(int i {}; i < 8; i++)
	{
		// basically i will represent 'n' in the 2^n place value equation
		sum = sum + (pow(2, i) * this->byte[i]);
	}
	return sum;
}

ByteStruc::~ByteStruc()
{
	// reallocate the array 
	delete [] byte;
}
