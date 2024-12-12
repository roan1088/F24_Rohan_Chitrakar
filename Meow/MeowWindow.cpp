#include "pch.h"
#include "MeowWindow.h"
#include "codeGLFW/WindowGLFW.h"

namespace Meow {

MeowWindow::MeowWindow() {
	#ifdef MEOW_GLFW
	implementation = std::unique_ptr<WindowImpl>{new WindowGLFW};
	#else
	#window_implementation_isnt_chosen
	#endif
}

void MeowWindow::Init() {
	if (instance == nullptr) {
		instance = std::unique_ptr<MeowWindow>{new MeowWindow};
	}
}

std::unique_ptr<MeowWindow>& MeowWindow::GetWindow() {
	return instance;
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

void MeowWindow::SetKeyEventHandler(const std::function<void(const KeyEvent&)>& newHandler) {
	implementation->SetKeyEventHandler(newHandler);
}

void MeowWindow::SetWindowEventHandler(const std::function<void(const WindowEvent&)>& newHandler) {
	implementation->SetWindowEventHandler(newHandler);
}

void MeowWindow::SwapBuffers() {
	implementation->SwapBuffers();
}

void MeowWindow::PollEvents() {
	implementation->PollEvents();
}

}