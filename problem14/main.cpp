/// Problem 14
/// Using the following rules:
/// n -> n / 2 (if n is even)
/// n -> 3n + 1 (if n is odd)
/// What is the longest chain generated, starting with numbers under one million,
/// until the result is 1?

#include <iostream>
#include "AutoTimer.h"

static constexpr int OneMillion = 1'000'000;

int main(int argc, char** argv)
{
	AutoTimer timer;

	// Variables to hold the results
	long long bestNumber = 1;
	long long bestChainSize = 1;

	for (long long i = 1; i < OneMillion; i++)
	{
		long long chainSize = 1;
		long long number = i;
		while (number != 1)
		{
			if (number % 2 == 0)
			{
				number = number / 2;
			}
			else
			{
				number = (number * 3) + 1;
			}
			chainSize++;
		}
		if (chainSize > bestChainSize)
		{
			bestChainSize = chainSize;
			bestNumber = i;
		}
	}

	std::cout << "The number that produces the longest chain is " << bestNumber << "." << std::endl;

	return 0;
}