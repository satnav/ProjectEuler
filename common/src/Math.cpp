#include "Math.h"

namespace Math
{
    std::map<int, int> PrimeFactors(int number)
    {
        // Stores the base and powers
        std::map<int, int> primeFactors;

        // Exclude anything below 2
        int divisor = 2;
        while (number > 1)
        {
            if (number % divisor == 0)
            {
                // Increment power of prime factor
                primeFactors[divisor]++;
                number /= divisor;
                divisor = 2;
            }
            else
            {
                divisor++;
            }
        }

        return primeFactors;
    }

    int SumOfDivisors(int number)
    {
        int product = 1;
        for (int divisor = 2; divisor * divisor <= number; ++divisor)
        {
            int p = 1;
            while (number % divisor == 0)
            {
                p = p * divisor + 1;
                number /= divisor;
            }
            product *= p;
        }

        if (number > 1)
        {
            product *= 1 + number;
        }

        return product;
    }
}