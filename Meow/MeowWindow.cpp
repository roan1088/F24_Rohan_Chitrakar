#include "pch.h"
#include "MeowWindow.h"
#include "codeGLFW/WindowGLFW.h"

namespace Meow {

MeowWindow::MeowWindow() {
	#ifdef MEOW_GLFW
	implementation = new WindowGLFW;
	#else
	#window_implementation_isnt_chosen
	#endif
}

void MeowWindow::CreateWindow(int width, int height, std::string windowName) {
	implementation->Create(width, height, windowName);
}

int MeowWindow::GetWidth() const {
	return implementation->GetWidth();
}

int MeowWindow::GetHeight() const {
	return implementation->GetHeight();
}

}