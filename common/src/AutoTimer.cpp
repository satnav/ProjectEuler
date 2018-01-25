#include "AutoTimer.h"

#include <iostream>

AutoTimer::AutoTimer()
{
    mStart = clock::now();
}

AutoTimer::~AutoTimer()
{
    auto end = clock::now();
    auto timePeriod = end - mStart;
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(timePeriod);
    std::cout << "Time elapsed: " << duration.count() << " milliseconds." << std::endl;
}
