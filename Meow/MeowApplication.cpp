#include "pch.h"
#include "MeowApplication.h"
#include "MeowWindow.h"

#include "Renderer.h"

namespace Meow {

void MeowApplication::Run() {
	Meow::MeowWindow::Init();
	Meow::MeowWindow::GetWindow()->CreateWindow(800, 600, "test");
	Meow::Renderer::Init();

	Initialize();

	mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

	while (shouldContinue) {
		Renderer::ClearScreen();

		Update();

		std::this_thread::sleep_until(mNextFrameTime);
		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;
		Meow::MeowWindow::GetWindow()->SwapBuffers();
		Meow::MeowWindow::GetWindow()->PollEvents();
	}

	Shutdown();
}
void MeowApplication::Initialize() {}
void MeowApplication::Update() {}
void MeowApplication::Shutdown() {}

}