#pragma once

#include <chrono>

class Timer {
public:
	void Reset();
	float GetTime() const;

private:
	std::chrono::steady_clock::time_point clock_begin{std::chrono::steady_clock::now()};
};