#pragma once

#include "../WindowImpl.h"
#include "GLFW/glfw3.h"

namespace Meow {

class WindowGLFW : public WindowImpl {
public:
	WindowGLFW();

	virtual void Create(int width, int height, std::string windowName) override;
	virtual int GetWidth() const override;
	virtual int GetHeight() const override;

	virtual void SwapBuffers() override;
	virtual void PollEvents() override;

private:
	GLFWwindow* windowPtr{nullptr};
};

}