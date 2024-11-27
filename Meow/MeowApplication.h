#pragma once

#include "pch.h"
#include "MeowUtilities.h"

constexpr int FRAME_RATE{60};

namespace Meow {

class MEOW_API MeowApplication {
public:
	void Run();
	virtual void Initialize();
	virtual void Update();
	virtual void Shutdown();

private:
	bool shouldContinue{true};

	std::chrono::steady_clock::time_point mNextFrameTime;
	std::chrono::milliseconds mFrameDuration{std::chrono::milliseconds{1000} / FRAME_RATE};
};

}