/// Problem 1
/// Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>
#include "AutoTimer.h"

int main(int argc, char** argv)
{
	AutoTimer timer;

	int sum = 0;
	for (int i = 3; i < 1000; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	std::cout << "The sum of all the multiples of 3 or 5 below 1000 is " 
		<< sum << "." << std::endl;
	
	return 0;
}
