/// Problem 9
/// There exists one Pythagorean triplem for which a + b + c = 1000.
/// Find the product abc.

#include <cmath>
#include <iostream>
#include "AutoTimer.h"

/// Determines if the number is a perfect square.
/// @param[in] number The number to test.
/// @return If the number is a perfect square.
bool IsPerfectSquare(long long number)
{
	long long squareRoot = (long long)round(sqrt(number));
	return squareRoot * squareRoot == number;
}

int main(int argc, char** argv)
{
	AutoTimer timer;

	for (int p1 = 1; p1 <= 1000; p1++)
	{
		for (int p2 = p1 + 1; p2 <= 1000; p2++)
		{
			// The result of 2 squares must be a square
			long long result = pow(p1, 2) + pow(p2, 2);
			if (IsPerfectSquare(result))
			{
				int p3 = round(sqrt(result));
				int sum = p1 + p2 + p3;
				if (sum == 1000)
				{
					long long product = p1 * p2 * p3;
					std::cout << "The product is " << product << "." << std::endl;
					return 0;
				}
			}
		}
	}
}