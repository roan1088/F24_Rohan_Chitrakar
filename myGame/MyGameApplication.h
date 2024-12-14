#pragma once

#include "Meow.h"
#include <array>

class MyGameApplication : public Meow::MeowApplication {
public:
	struct Position {
		float x;
		float y;
	};

	virtual void Initialize() override;
	virtual void Update() override;

	void SetUpBackground();
	void DrawBackground();
	void MoveBackground();

private:
	int windowWidth{Meow::MeowWindow::GetWindow()->GetWidth()};
	int windowHeight{Meow::MeowWindow::GetWindow()->GetHeight()};
	std::array<Meow::Image, 3> stars;
	std::array<Position, 128> background;
};