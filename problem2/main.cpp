/// Problem 2
/// By considering the terms in the Fibonacci sequence whose values do not
/// exceed four million, find the sum of the even-valued terms.

#include <iostream>
#include "AutoTimer.h"

constexpr int FourMillion = 4'000'000;

int main(int argc, char** argv)
{
	AutoTimer timer;

	int f1 = 1;
	int f2 = 2;
	int f3 = f1 + f2;
	int sum = 2;

	while (f3 <= FourMillion)
	{
		if (f3 % 2 == 0)
		{
			sum += f3;
		}

		f1 = f2;
		f2 = f3;
		f3 = f1 + f2;
	}

	std::cout << "The sum of the even valued terms is " << sum << "." << std::endl;

	return 0;
}