#include "Meow.h"
#include <iostream>

class MyGameApplication : public Meow::MeowApplication {
	virtual void Initialize() override {
		std::cout << "Starting..." << std::endl;
	}
	virtual void Update() override {
		// std::cout << "Running..." << std::endl;
	}
};

MEOW_GAME_START(MyGameApplication)