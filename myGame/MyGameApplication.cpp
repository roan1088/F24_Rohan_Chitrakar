#include "MyGameApplication.h"

#include <cstdlib>
#include <ctime>

void MyGameApplication::Initialize() {
	MEOW_LOG("Starting...");
	srand(time(nullptr));

	SetUpBackground();
}

void MyGameApplication::Update() {
	DrawBackground();
	MoveBackground();
}

void MyGameApplication::SetUpBackground() {
	stars[0].LoadImage("../myGame/assets/background/stars0.png");
	stars[1].LoadImage("../myGame/assets/background/stars1.png");
	stars[2].LoadImage("../myGame/assets/background/stars2.png");

	for (int i = 0; i < background.size(); i++) {
		background[i].x = windowWidth * i / (background.size() - 1);
		background[i].y = rand() % windowHeight;
	}
}

void MyGameApplication::DrawBackground() {
	for (int i = 0; i < background.size(); i++) {
		Meow::Renderer::Draw(stars[i % 3], background[i].x, background[i].y);
	}
}

void MyGameApplication::MoveBackground() {
	for (int i = 0; i < background.size(); i++) {
		background[i].x -= 0.4;
		if (background[i].x <= -stars[i % 3].GetWidth()) {
			background[i].x = windowWidth;
		}
	}
}