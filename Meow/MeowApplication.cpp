#include "pch.h"
#include "MeowApplication.h"

namespace Meow {

void MeowApplication::Run() {
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