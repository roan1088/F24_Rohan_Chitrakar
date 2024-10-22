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

}