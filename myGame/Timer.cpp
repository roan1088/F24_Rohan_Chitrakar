#include "Timer.h"

void Timer::Reset() {
	clock_begin = std::chrono::steady_clock::now();
}

float Timer::GetTime() const {
	std::chrono::duration<float> duration = std::chrono::steady_clock::now() - clock_begin;
	return duration.count();
}
