/// Problem 5
/// What is the smallest positive number that is evenly divisible by all
/// of the numbers from 1 to 20?

#include <iostream>
#include "AutoTimer.h"

int main(int argc, char** argv)
{
	AutoTimer timer;

	for (int i = 1; ; i++)
	{
		bool allDivisible = true;
		for (int j = 1; j <= 20; j++)
		{
			if (i % j != 0)
			{
				allDivisible = false;
				break;
			}
		}

		if (allDivisible)
		{
			std::cout << "The smallest number is " << i << "." << std::endl;
			break;
		}
	}

	return 0;
}