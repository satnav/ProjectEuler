#pragma once

#include <chrono>

/// A timer which automatically reports elapsed time after destruction.
class AutoTimer
{
public:
    /// Constructs a new AutoTimer object.
    AutoTimer();

    /// Destructs the AutoTimer object and reports elapsed time.
    ~AutoTimer();

private:
    /// An alias for the underlying clock being used.
    using clock = std::chrono::high_resolution_clock;

    /// The time point where the clock is first instantiated.
    std::chrono::time_point<clock> mStart;
};
