#pragma once

#include "Meow.h"
#include <array>
#include <vector>
#include "Timer.h"

constexpr int PLAYER_SPEED{8};
constexpr int ASTEROID_SPEED{-4};

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

	void UpdatePlayerPosition();

	void DrawAsteroids();
	void SpawnAsteroid();
	void UpdateAsteroids();

	bool CheckCollision();

	void KeyEventHandler(const Meow::KeyEvent& event);

private:
	int windowWidth{Meow::MeowWindow::GetWindow()->GetWidth()};
	int windowHeight{Meow::MeowWindow::GetWindow()->GetHeight()};
	std::array<Meow::Image, 3> stars;
	std::array<Position, 128> background;
	Meow::Unit player{"../myGame/assets/player/orange_cat.png", windowWidth / 2, windowHeight / 2};
	Position player_movement{0, 0};
	Timer timer;
	std::vector<Meow::Unit> asteroids;
};