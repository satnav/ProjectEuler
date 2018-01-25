/// Problem 22
/// In the Names.txt file, first sort the names by alphabetical order. Then
/// working out the alphabetical value for each name, multiply this value by
/// its alphabetical position in the list to obtain a name score. What is the
/// total of all the names scores in the file?

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "AutoTimer.h"

/// Loads the file with names and puts them into a vector.
std::vector<std::string> LoadFile()
{
	// Get handle to file
	std::ifstream file("../problem22/Names.txt");

	// Check if successful
	if (file)
	{
		// Create vector to store results
		std::vector<std::string> names;
		
		// Ignore quotation marks, delimit on commas
		while (file)
		{
			std::string name;
			int c = ' ';
			
			while (c != ',' && c != EOF)
			{
				c = file.get();
				if (c != '"' && c != ',')
				{
					name += c;
				}
			}

			// Add name to vector
			std::cout << "Found name " << name << std::endl;
			names.push_back(name);
		}

		// Returm result
		return names;
	}
	else
	{
		std::cerr << "Could not open file." << std::endl;
		exit(1);
	}
}

/// Sorts the list of names into alphabetical order.
void SortNames(std::vector<std::string>& names)
{
	std::cout << "Starting sorting" << std::endl;
	std::sort(names.begin(), names.end());
	std::cout << "Finished sorting" << std::endl;
}

/// Calculates the alphabetical value of the name.
unsigned long long GetAlphabeticalValue(const std::string& name)
{
	// Store the result
	unsigned long long sum = 0;

	// Iterate over evey letter
	for (size_t i = 0; i < name.size(); i++)
	{
		if (name[i] >= 'A' && name[i] <= 'Z')
		{
			// 'A' is 65 so take 64
			sum += (name[i] - 64);
		}
		else
		{
			std::cerr << "Name [" << name << "] has invalid character: " << name[i] << std::endl;
		}
	}
	return sum;
}

int main(int argc, char** argv)
{
	AutoTimer timer;
	
	// Do preparation work
	auto names = LoadFile();
	SortNames(names);

	// Store results
	unsigned long long sum = 0;

	// Iterate over every name
	for (size_t i = 0; i < names.size(); i++)
	{
		std::string& n = names[i];
		unsigned long long value = GetAlphabeticalValue(n) * (i + 1);
		sum += value;

		std::cout << "Calculated name #" << (i + 1) << ": " << n << " = " << value << std::endl;
	}

	// Print result
	std::cout << "The total of all the name scores is " << sum << "." << std::endl;
	return 0;
}
