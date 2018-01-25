/// Problem 23
/// A number n is called abundant if the sum of its proper divisors
/// exceeds n. Find the sum of all the positive integers which
/// cannot be written as the sum of two abundant numbers. By
/// mathematical analysis, it can be shown that all integers greater
/// than 28123 can be written as the sum of two abundant numbers.

#include <iostream>
#include <vector>
#include "AutoTimer.h"

/// The upper limit for checking abundant numbers.
static constexpr int UpperLimit = 28123;

/// Calculates the sum of divisors of a number.
/// @param[in] number The number to sum divisors for.
/// @return The sum of divisors.
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

int main(int argc, char** argv)
{
    // Start the timer
    AutoTimer timer;

    // Get abundant numbers
    std::vector<int> abundant;
    for (int i = 2; i <= UpperLimit; ++i)
    {
        if (SumOfDivisors(i) > 2 * i)
        {
            abundant.push_back(i);
        }
    }

    // Calculate sums of two abundant numbers
    // This avoids an array bounds comparison
    bool sumOfAbundant[UpperLimit * 2 + 1] = { false };
    for (size_t i = 0; i < abundant.size(); ++i)
    {
        for (size_t j = 0; j <= i; ++j)
        {
            sumOfAbundant[abundant[i] + abundant[j]] = true;
        }
    }

    // Calculate sum of those that cannot be expressed
    int sum = 0;
    for (size_t i = 1; i < UpperLimit; ++i)
    {
        if (!sumOfAbundant[i])
        {
            sum += i;
        }
    }

    std::cout << "the sum of all the positive integers which "
        "cannot be written as the sum of two abundant numbers is " << sum << "." << std::endl;
    return 0;
}