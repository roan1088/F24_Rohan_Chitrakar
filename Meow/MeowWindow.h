#pragma once

#include "pch.h"
#include "WindowImpl.h"
#include "MeowUtilities.h"
#include "MeowEvents.h"

namespace Meow {

class MEOW_API MeowWindow {
public:
	static void Init();
	static std::unique_ptr<MeowWindow>& GetWindow();

	void CreateWindow(int width, int height, std::string windowName);
	int GetWidth() const;
	int GetHeight() const;

	void SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler);
	void SetWindowEventHandler(const std::function<void(const WindowEvent&)>& newHandler);

	void SwapBuffers();
	void PollEvents();

private:
	std::unique_ptr<WindowImpl> implementation{nullptr};

	MeowWindow();
	inline static std::unique_ptr<MeowWindow> instance;
};

}