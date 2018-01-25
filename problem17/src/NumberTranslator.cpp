#include "NumberTranslator.h"

std::string NumberTranslator::Translate(int number)
{
	// Check special cases
	if (number == 0)
	{
		return NumberMap[0];
	}

	std::string numberAsWords;
	int onesDigit = 0, tensDigit = 0;
	int place = 1;
	while (number != 0)
	{
		int nextDigit = number % 10;

		if (place == 100 && (onesDigit != 0 || tensDigit != 0))
		{
			numberAsWords = "and " + numberAsWords;
		}

		if (nextDigit != 0)
		{
			if (place == 1000)
			{
				numberAsWords = NumberMap[nextDigit] + " " + NumberMap[1000] + " " + numberAsWords;
			}
			else if (place == 100)
			{
				numberAsWords = NumberMap[nextDigit] + " " + NumberMap[100] + " " + numberAsWords;
			}
			else if (place == 10)
			{
				tensDigit = nextDigit;
				if (nextDigit == 1)
				{
					int index = 10 + onesDigit;
					numberAsWords = NumberMap[index];
				}
				else
				{
					if (onesDigit == 0)
					{
						numberAsWords = NumberMap[nextDigit * 10];
					}
					else
					{
						numberAsWords = NumberMap[nextDigit * 10] + "-" + numberAsWords;
					}
				}
			}
			else if (place == 1)
			{
				numberAsWords = NumberMap[nextDigit];
				onesDigit = nextDigit;
			}
		}

		place *= 10;
		number /= 10;
	}

	return numberAsWords;
}
