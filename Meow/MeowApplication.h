#pragma once

#include "pch.h"
#include "MeowUtilities.h"
#include "MeowEvents.h"

constexpr int FRAME_RATE{60};

namespace Meow {

class MEOW_API MeowApplication {
public:
	void Run();
	virtual void Initialize();
	virtual void Update();
	virtual void Shutdown();

	void SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler);
	void SetWindowEventHandler(const std::function<void(const WindowEvent&)>& newHandler);

private:
	bool shouldContinue{true};

	std::chrono::steady_clock::time_point mNextFrameTime;
	std::chrono::milliseconds mFrameDuration{std::chrono::milliseconds{1000} / FRAME_RATE};
};

}