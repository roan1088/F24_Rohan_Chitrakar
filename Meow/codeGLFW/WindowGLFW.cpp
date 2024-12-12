#include "pch.h"
#include "WindowGLFW.h"
#include "MeowUtilities.h"

namespace Meow {

WindowGLFW::WindowGLFW() {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void WindowGLFW::Create(int width, int height, std::string windowName) {
	windowPtr = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
	if (!windowPtr) {
		MEOW_ERROR("GLFW failed to create a window!!!");
	}
	glfwMakeContextCurrent(windowPtr);

	glfwSetWindowUserPointer(windowPtr, &mCallbacks);
	glfwSetKeyCallback(windowPtr,
	[](GLFWwindow* window, int key, int scancode, int action, int mods) {
		Callbacks* callbacks{(Callbacks*) glfwGetWindowUserPointer(window)};

		if (action == GLFW_PRESS) {
			KeyEvent event{ key, KeyEvent::KeyAction::PRESS};
			callbacks->KeyEventHandler(event);
		} else if (action == GLFW_RELEASE) {
			KeyEvent event{ key, KeyEvent::KeyAction::RELEASE};
			callbacks->KeyEventHandler(event);
		} else if (action == GLFW_REPEAT) {
			KeyEvent event{ key, KeyEvent::KeyAction::REPEAT};
			callbacks->KeyEventHandler(event);
		}
	});

	glfwSetWindowCloseCallback(windowPtr, [](GLFWwindow* window) {
		Callbacks* callbacks{(Callbacks*) glfwGetWindowUserPointer(window)};

		WindowEvent event{WindowEvent::WindowAction::CLOSE};
		callbacks->WindowEventHandler(event);
	});
}

int WindowGLFW::GetWidth() const {
	int width{0};
	glfwGetWindowSize(windowPtr, &width, NULL);
	return width;
}

int WindowGLFW::GetHeight() const {
	int height{0};
	glfwGetWindowSize(windowPtr, NULL, &height);
	return height;
}

void WindowGLFW::SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler) {
	mCallbacks.KeyEventHandler = newHandler;
}

void WindowGLFW::SetWindowEventHandler(const std::function<void(const WindowEvent&)>& newHandler) {
	mCallbacks.WindowEventHandler = newHandler;
}

void WindowGLFW::SwapBuffers() {
	glfwSwapBuffers(windowPtr);
}

void WindowGLFW::PollEvents() {
	glfwPollEvents();
}

}