/// Problem 4
/// What is the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <sstream>
#include <string>
#include "AutoTimer.h"

/// Determines if the number is a palindrome.
/// @param[in] The number to test.
/// @return Whether the number is a palidrome.
bool IsPalindrome(int number)
{
	// Convert number to a string
	std::stringstream stream;
	stream << number;
	std::string text(stream.str());

	// Test both ends iterating inwards
	for (int i = 0; i < text.size() / 2; i++)
	{
		if (text[i] != text[text.size() - i - 1])
		{
			return false;
		}
	}

	return true;
}

int main(int argc, char** argv)
{
	AutoTimer timer;

	int largestProduct = 0;

	for (int i = 100; i <= 999; i++)
	{
		for (int j = i; j <= 999; j++)
		{
			int product = i * j;
			if (IsPalindrome(product))
			{
				if (product > largestProduct)
				{
					largestProduct = product;
				}
			}
		}
	}

	std::cout << "The largest palindrome product is " << largestProduct << "." << std::endl;
}