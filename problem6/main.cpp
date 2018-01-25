/// Problem 6
/// Find the difference between the sum of the squares of the first one hundred
/// natural numbers and the square of the sum.

#include <cmath>
#include <iostream>
#include "AutoTimer.h"

/// Calculates the sum of square numbers.
/// @param[in] upperLimit The highest number to square then sum.
/// @return The sum of squares.
long long SumOfSquares(int upperLimit)
{
	long long sum = 0;
	for (int i = 1; i <= upperLimit; i++)
	{
		sum += pow(i, 2);
	}
	return sum;
}

/// Calculates the square of a sum.
/// @param[in] upperLimit The highest number to sum then square.
/// @return The square of a sum.
long long SquareOfSum(int upperLimit)
{
	long long sum = 0;
	for (int i = 1; i <= upperLimit; i++)
	{
		sum += i;
	}
	return pow(sum, 2);
}

int main(int argc, char** argv)
{
	AutoTimer timer;

	long long answer = SquareOfSum(100) - SumOfSquares(100);
	std::cout << "The difference is " << answer << "." << std::endl;
	return 0;
}