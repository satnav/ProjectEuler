/// Problem 24
/// What is the millionth lexicographic permuation of the digits:
/// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9?

#include <algorithm>
#include <iostream>
#include <string>
#include "AutoTimer.h"

static std::string Digits = "0123456789";

int main(int argc, char** argv)
{
    AutoTimer timer;

    for (int i = 0; i < 999'999; i++)
    {
        std::next_permutation(Digits.begin(), Digits.end());
    }
    std::cout << "The millionth lexicographic permutation is " << Digits 
        << "." << std::endl;
    return 0;
}
