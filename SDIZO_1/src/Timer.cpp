#include "Timer.h"

void Timer::start()
{
	startTime = std::chrono::high_resolution_clock::now();
}

void Timer::stop()
{
	endTime = std::chrono::high_resolution_clock::now();
}

__int64 Timer::getTime()
{
	return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count();
}
