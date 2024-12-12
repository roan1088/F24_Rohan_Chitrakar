#pragma once

#include "../WindowImpl.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"

#include "pch.h"
#include "MeowEvents.h"

namespace Meow {

class WindowGLFW : public WindowImpl {
public:
	WindowGLFW();

	virtual void Create(int width, int height, std::string windowName) override;
	virtual int GetWidth() const override;
	virtual int GetHeight() const override;

	virtual void SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler) override;
	virtual void SetWindowEventHandler(const std::function<void(const WindowEvent&)>& newHandler) override;

	virtual void SwapBuffers() override;
	virtual void PollEvents() override;

private:
	GLFWwindow* windowPtr{nullptr};

	struct Callbacks
	{
		std::function<void(const KeyEvent&)> KeyEventHandler{[](const KeyEvent&) {}};
		std::function<void(const WindowEvent&)> WindowEventHandler{[](const WindowEvent&) {}};
	} mCallbacks;
};

}