#pragma once

#include <map>

/// Contains helpful math functions.
namespace Math
{
    /// Calculates the prime factors of a number.
    /// @param[in] number The number to calculate prime factors for.
    /// @return A map of prime factors to their power.
    std::map<int, int> PrimeFactors(int number);

    /// Calculates the sum of divisors of a number.
    /// @param[in] number The number to sum divisors for.
    /// @return The sum of divisors.
    int SumOfDivisors(int number);
}
