#include <iostream>

class ByteStruc
{
private:
	bool *byte;
public:

	// num to byte func
	static void num_to_byte(int in_num, bool *returnable)
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
			int i{ 0 };
			int dif{ 128 };

			// loop til' end of array :^)
			while (i <= 7)
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
				i++;
			}
		}
		returnable = nullptr;
	}
	
	// creates a twos-complement byte
	static void num_to_byte_twos_comp(int in_num, bool *returnable)
	{
		// this should fill out the byte with the last bit being a positive or negative flag
		
		// check if number is between 128 to -128
		if ((in_num >= 128) || (in_num <= -128))
		{
			std::cout << "number too large or small!" << std::endl;
		}
		else
		{
			int i{0};
			int dif{64};

			// if number is a negative switch the sign, and set the last bool to 1
			if( in_num > 0)
			{
				//
			}

		}

	}


	ByteStruc(int temp_int)
	{
		//make new bool array on heap
		this->byte = new bool[8];
	
		// send the int and bool array to the num_to_byte function
		num_to_byte(temp_int, this->byte);

		std::cout << "completed Byte contstruction" << std::endl;
	}

	void print_byte()
	{
		std::cout << "printing byte:" << std::endl;
		for (int i{}; i <= 7; i++)
		{
			std::cout << "byte at [" << i << "]: " << this->byte[i] << std::endl;
		}
	}

	
	~ByteStruc()
	{
		// reallocate the array 
		delete [] byte;
	}
};
