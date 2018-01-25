/// Problem 25
/// What is the index of the first term in the Fibonacci sequence to contain
/// 1000 digits?

#include <cmath>
#include <iostream>
#include "AutoTimer.h"

static constexpr double GoldenRatio = 1.6180;

int main(int argc, char** argv)
{
    // For large enough n:
    // F(n) = round(GR^n / sqrt(5))
    // round(GR^n / sqrt(5)) > 10^999

    AutoTimer timer;

    int index = round((log(10) * 999 + (log(5) / 2)) / log(GoldenRatio));
    std::cout << "The index of the first term is " << index << std::endl;
    return 0;
}
