#include <cstdio>
#include <iostream>
#include <ostream>

int main()
{
	double scores[] = {5.5, 6.5, 7.3, 1.2, 3.8, 9.1, 10};
	double high_percent {}, med_percent{}, low_percent{};
	double high_av {}, med_av{}, low_av{};
	
	int num_of_scores {7};
	
	std::cout << "high percent weight: (in dec): " << std::endl;
	std::cin >> high_percent;
	std::cout << "medium: " << std::endl;
	std::cin >> med_percent;
	std::cout << "low: " << std::endl;
	std::cin >> low_percent;
	
	// do some data stuff
	for( int i{}; i < num_of_scores; i++)
	{
		if (scores[i] >= 8)
		{
			// score is high
			high_av += scores[i];
		}
		else if (scores[i] <= 7.9 && scores[i] >= 5)
		{
			// score is medium
			med_av += scores[i];
		}
		else if (scores[i] <= 4.9 && scores[i] >=1)
		{
			// score is low
			low_av += scores[i];
		}
		else {
			std::cout << "val too low, or something went wrong" << std::endl;
		}
	}
	
	std::cout << high_av << std::endl;
	std::cout << med_av << std::endl;
	std::cout << low_av << std::endl;

	std::cout << "---------" << std::endl;
	double high = (high_av * high_percent);
	double med = (med_av * med_percent);
	double low = (low_av * low_percent);
	std::cout << high << std::endl;
	std::cout << med << std::endl;
	std::cout << low << std::endl;
	double answer = (high + med + low) / num_of_scores;
	
	std::cout << answer << std::endl;
	// I don't know why this is wrong lmoa
	
	return 0;
}
