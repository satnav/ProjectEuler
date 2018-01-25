/// Problem 17
/// If all the numbers from 1 to 1000 inclusive were written out as words,
/// how many letters would be used?

#include <iostream>
#include "AutoTimer.h"
#include "NumberTranslator.h"

/// Counts the characters in the generated number.
/// Excludes spaces and hyphens
int CountCharacters(const std::string& number)
{
	int count = 0;
	for (size_t i = 0; i < number.size(); i++)
	{
		if (number[i] == ' ' || number[i] == '-')
		{
			continue;
		}
		count++;
	}
	return count;
}

int main(int argc, char** argv)
{
	AutoTimer timer;

	NumberTranslator t;
	int sum = 0;
	for (int i = 1; i <= 1000; i++)
	{
		std::string number = t.Translate(i);
		std::cout << i << " - " << number << std::endl;
		sum += CountCharacters(number);
	}
	std::cout << "The final number of characters is " << sum << std::endl;
	return 0;
}
