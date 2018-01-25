/// Problem 19
/// How many Sundays fell on the first month during the 20th century?

#include <iostream>
#include "AutoTimer.h"

static int Months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main(int argc, char** argv)
{
	AutoTimer timer;

	int day = 2;
	int sundayCount = 0;

	for (int i = 1901; i < 2001; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			day += Months[j];
			if (i % 4 == 0 && j == 1)
			{
				day++;
			}
			if (day % 7 == 0)
			{
				sundayCount += 1;
			}
		}
	}

	std::cout << "The number of sundays is " << sundayCount << std::endl;
	return 0;
}
