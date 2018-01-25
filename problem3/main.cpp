/// Problem 3
/// What is the largest prime factor of the number 600851475143?

#include <iostream>
#include "AutoTimer.h"

constexpr long long Number = 600851475143;

int main(int argc, char** argv)
{
	AutoTimer timer;

	long long currentNumber = Number;
	long long currentFactor = 2;
	long long largestFactor = 1;

	while (currentNumber != 1)
	{
		if (currentNumber % currentFactor == 0)
		{
			currentNumber /= currentFactor;
			if (currentFactor > largestFactor)
			{
				largestFactor = currentFactor;
			}
			currentFactor = 2;
		}
		else
		{
			currentFactor++;
		}
	}

	std::cout << "The largest prime factor of 600851475143 is " << largestFactor
		<< "." << std::endl;

	return 0;
}