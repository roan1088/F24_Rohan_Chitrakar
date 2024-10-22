#include "Meow.h"
#include <iostream>

class MyGameApplication : public Meow::MeowApplication {
	virtual void Initialize() override {
		MEOW_LOG("Starting...");
		MEOW_ERROR("Test error message...");
		Meow::MeowWindow win;
		win.CreateWindow(800, 600, "test");
	}

	virtual void Update() override {
		// std::cout << "Running..." << std::endl;
	}
};

MEOW_GAME_START(MyGameApplication)