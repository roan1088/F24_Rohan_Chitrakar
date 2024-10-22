#include "pch.h"
#include "MeowApplication.h"
#include "MeowWindow.h"

namespace Meow {

void MeowApplication::Run() {
	Meow::MeowWindow::Init();
	Meow::MeowWindow::GetWindow()->CreateWindow(800, 600, "test");
	
	Initialize();

	while (shouldContinue) {
		Update();
	}

	Shutdown();
}
void MeowApplication::Initialize() {}
void MeowApplication::Update() {}
void MeowApplication::Shutdown() {}

}