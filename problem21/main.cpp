/// Problem 21
/// Let d(n) be defined as the sum of proper divisors of n (numbers less than n
/// which divide evenly into n). If d(a) = b and d(b) = a, where a != b, then
/// a and b are an amicable pair and each of a and b are called amicable numbers.
/// Evaluate the sum of all the amicable numbers under 10000.

#include <cmath>
#include <iostream>
#include "AutoTimer.h"

/// Returns the sum of the proper divisors of the number.
int SumOfDivisors(int number)
{
	// Guard against other numbers
	if (number <= 1)
	{
		return 0;
	}

	// 1 is always a divisor
	int result = 1;

	// All prime factors are <= sqrt(number)
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
		{
			if (i == (number / i))
			{
				result += i;
			}
			else
			{
				result += (i + number / i);
			}
		}
	}

	return result;
}

int main(int argc, char** argv)
{
	AutoTimer timer;

	// Store the sum
	int sum = 0;

	// Sum all amicable numbers under 10000
	for (int i = 0; i < 10000; i++)
	{
		int p1 = SumOfDivisors(i);
		int p2 = SumOfDivisors(p1);

		if (i == p2 && p1 != p2)
		{
			// Only store one so we don't double up
			sum += p1;
		}
	}

	// Print the result
	std::cout << "The sum of all amicable numbers under 10000 is " << sum << "." << std::endl;
	return 0;
}
