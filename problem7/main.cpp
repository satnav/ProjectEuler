/// Problem 7
/// What is the 10,001st prime number?

#include <cmath>
#include <iostream>
#include "AutoTimer.h"

/// Determines whether a number is prime or not.
/// @param[in] number The number to test.
/// @return Whether the number is prime or not.
bool IsPrime(int number)
{
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			return false;
		}
	}
	
	return true;
}

/// Gets the prime number at the specified position.
/// @param[in] position The prime number position to calculate.
/// @return The prime number at the position.
int Prime(int position)
{
	int counter = 0;
	int current = 1;
	while (counter < position)
	{
		current++;
		if (IsPrime(current))
		{
			counter++;
		}
	}
	return current;
}

int main(int argc, char** argv)
{
	AutoTimer timer;

	std::cout << "The 10001st prime number is " << Prime(10'001) << "." << std::endl;
	return 0;
}