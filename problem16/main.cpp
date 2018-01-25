/// Problem 16
/// What is the sum of the digits of the number 2^1000?

#include <iostream>
#include "AutoTimer.h"
#include "BigInteger.h"

int main(int argc, char** argv)
{
	AutoTimer timer;

	BigInteger number(1);
	for (int i = 0; i < 1000; i++)
	{
		number *= 2;
	}

	auto digits = number.GetDigits();
	int sum = 0;
	for (size_t i = 0; i < digits.size(); i++)
	{
		sum += digits[i];
	}
	std::cout << "The sum of the digits is " << sum << "." << std::endl;
	
	return 0;
}