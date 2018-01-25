/// Problem 12
/// What is the value of the first triangle number to have over five hundred
/// divisors?

#include <iostream>
#include <map>
#include "AutoTimer.h"

/// Calculates the next triangle number. 
/// A triangle number x is the sum of all integers from 1 to x.
/// @return The next triangle number.
long long GetNextTriangleNumber()
{
	static long long i = 0;
	static long long sum = 0;

	i++;
	sum += i;
	return sum;
}

/// Calculates the number of divisors of a number.
/// The number of divisors can be calculated by multiplying the
/// power, plus one, of the prime factors of the number.
/// e.g. prime factors of 20 = 5^1 * 2*2, therefore (1 + 1) * (2 + 1) = 6 divisors.
/// @param[in] number The number to calculate the number of divisors.
/// @return The number of divisors.
int GetNumberOfDivisors(long long number)
{
	// Calculate the prime factors
	std::map<int, int> primeFactors;
	int z = 2;
	while (number != 1)
	{
		if (number % z == 0)
		{
			primeFactors[z]++;
			number /= z;
		}
		else
		{
			z++;
		}
	}

	// Calculate the divisors
	int divisors = 1;
	for (auto& pair : primeFactors)
	{
		divisors *= (pair.second + 1);
	}

	return divisors;
}

int main(int argc, char** argv)
{
	AutoTimer timer;

	long long triangleNumber;
	int divisors;
	do
	{
		triangleNumber = GetNextTriangleNumber();
		std::cout << "Triangle number: " << triangleNumber;
		divisors = GetNumberOfDivisors(triangleNumber);
		std::cout << ", divisors = " << divisors << std::endl;
	} while (divisors <= 500);

	std::cout << "The value is " << triangleNumber << "." << std::endl;

	return 0;
}
