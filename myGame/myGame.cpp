#include "Meow.h"
#include <array>
#include <cstdlib>
#include <ctime>

struct Position {
	float x;
	float y;
};

class MyGameApplication : public Meow::MeowApplication {
	int windowWidth, windowHeight;
	std::array<Meow::Image, 3> stars;
	std::array<Position, 128> background;

	virtual void Initialize() override {
		MEOW_LOG("Starting...");

		srand(time(nullptr));

		windowWidth = Meow::MeowWindow::GetWindow()->GetWidth();
		windowHeight = Meow::MeowWindow::GetWindow()->GetHeight();

		stars[0].LoadImage("../myGame/assets/background/stars0.png");
		stars[1].LoadImage("../myGame/assets/background/stars1.png");
		stars[2].LoadImage("../myGame/assets/background/stars2.png");

		for (int i = 0; i < background.size(); i++) {
			background[i].x = windowWidth * i / (background.size() - 1);
			background[i].y = rand() % windowHeight;
			// MEOW_LOG(background[i].x << " " << background[i].y);
		}
	}

	virtual void Update() override {

		for (int i = 0; i < background.size(); i++) {
			Meow::Renderer::Draw(stars[i % 3], background[i].x, background[i].y);
			background[i].x -= 0.4;
			if (background[i].x <= -stars[i % 3].GetWidth()) {
				background[i].x = windowWidth;
			}
		}

	}
};

MEOW_GAME_START(MyGameApplication)