/// Problem 20
/// Find the sum of the digits in the number 100!

#include <iostream>
#include "AutoTimer.h"
#include "BigInteger.h"

int main(int argc, char** argv)
{
	AutoTimer timer;

	BigInteger n(1);
	for (int i = 2; i <= 100; i++)
	{
		n *= i;
	}

	int sum = 0;
	for (auto& x : n.GetDigits())
	{
		sum += x;
	}

	std::cout << "The sum of the digits in the number 100! is " << sum << std::endl;
	return 0;
}
