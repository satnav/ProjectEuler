/// Problem 10
/// Find the sum of all the primes below two million

#include <cmath>
#include <iostream>
#include "AutoTimer.h"

constexpr int TwoMillion = 2'000'000;

/// Determines if the number is prime.
/// @param[in] number The number to test.
/// @return Whether the number is prime or not.
bool IsPrime(int number)
{
	// Negative numbers and numbers below 2 cannot be prime
	if (number < 2)
	{
		return false;
	}

	if (number == 2)
	{
		return true;
	}

	if (number % 2 == 0)
	{
		return false;
	}

	for (int i = 3; i <= sqrt(number); i += 2)
	{
		if (number % i == 0)
		{
			return false;
		}
	}

	return true;
}

int main(int argc, char** argv)
{
	AutoTimer timer;

	long long sum = 2;
	for (int i = 3; i < TwoMillion; i += 2)
	{
		if (IsPrime(i))
		{
			sum += i;
		}
	}

	std::cout << "The sum of all primes below two million is " << sum << "." << std::endl;
	return 0;
}