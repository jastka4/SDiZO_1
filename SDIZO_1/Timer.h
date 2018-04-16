#pragma once
#include <iostream>
#include <chrono>

class Timer
{
	std::chrono::high_resolution_clock::time_point startTime;
	std::chrono::high_resolution_clock::time_point endTime;
public:
	void start();
	void stop();
	unsigned long getTime();
};

