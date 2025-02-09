#include "MyGameApplication.h"

#include <cstdlib>
#include <chrono>

void MyGameApplication::Initialize() {
	MEOW_LOG("Starting...");
	MEOW_LOG("EPOCH: " << std::chrono::system_clock::now().time_since_epoch().count());
	srand(std::chrono::system_clock::now().time_since_epoch().count());

	SetKeyEventHandler([this](const Meow::KeyEvent& event) {KeyEventHandler(event);});

	SetUpBackground();

	timer.Reset();
}

void MyGameApplication::Update() {
	if (game_state == GameState::GAME_PLAY) {
		if (timer.GetTime() >= 3) {
			SpawnAsteroid();
			timer.Reset();
		}

		if (CheckCollision()) {
			MEOW_LOG("GAMEOVER!! Final score: " << scorer.GetScore());
			ChangeGameState(GameState::GAME_OVER);
		}

		MoveBackground();
		UpdateAsteroids();
	}

	if (game_state == GameState::GAME_OVER) {
		if (timer.GetTime() >= 3) {
			ChangeGameState(GameState::MAIN_MENU);
			scorer.Reset();
		}
	} else {
		UpdatePlayerPosition();
	}

	DrawBackground();
	Meow::Renderer::Draw(player);
	DrawAsteroids();
	scorer.DrawScore();

	if (game_state == GameState::MAIN_MENU) {
		DrawMainMenu();
	} else if (game_state == GameState::GAME_OVER) {
		DrawGameOver();
	}
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

void MyGameApplication::UpdatePlayerPosition() {
	player.UpdateXCoord(player_movement.x);
	player.UpdateYCoord(player_movement.y);

	int player_x{player.GetXCoord()};
	int player_y{player.GetYCoord()};

	if (player_x <= 0) {
		player_x = 0;
	} else if (player_x >= windowWidth - player.GetWidth()) {
		player_x = windowWidth - player.GetWidth();
	}
	if (player_y <= 0) {
		player_y = 0;
	} else if (player_y >= windowHeight - player.GetHeight()) {
		player_y = windowHeight - player.GetHeight();
	}

	player.SetCoords(player_x, player_y);
}

void MyGameApplication::DrawAsteroids() {
	for (int i = 0; i < asteroids.size(); i++) {
		Meow::Renderer::Draw(asteroids[i]);
	}
}

void MyGameApplication::SpawnAsteroid() {
	Meow::Unit asteroid{"../myGame/assets/asteroid/asteroid.png", 0, 0};
	int y = rand() % (windowHeight - asteroid.GetHeight());
	asteroid.SetCoords(windowWidth, y);
	asteroids.push_back(std::move(asteroid));
}

void MyGameApplication::UpdateAsteroids() {
	for (int i = 0; i < asteroids.size(); i++) {
		asteroids[i].UpdateXCoord(ASTEROID_SPEED);
		if (asteroids[i].GetXCoord() < -asteroids[i].GetWidth()) {
			asteroids.erase(asteroids.begin() + i);
			scorer.AddScore();
			MEOW_LOG(scorer.GetScore());
		}
	}
}

bool MyGameApplication::CheckCollision() {
	for (int i = 0; i < asteroids.size(); i++) {
		if (Meow::UnitsOverlap(player, asteroids[i])) {
			return true;
		}
	}
	return false;
}

void MyGameApplication::ChangeGameState(GameState new_state) {
	if (new_state == GameState::GAME_PLAY) {
		game_state = new_state;
		MEOW_LOG("Game State changed to Gameplay.");
		timer.Reset();
	} else if (new_state == GameState::MAIN_MENU) {
		game_state = new_state;
		MEOW_LOG("Game State changed to MainMenu.");
		asteroids.clear();
	} else if (new_state == GameState::GAME_OVER) {
		game_state = new_state;
		MEOW_LOG("Game State changed to GameOver.");
		timer.Reset();
	}
}

void MyGameApplication::DrawMainMenu() {
	Meow::Unit start_instruction{"../myGame/assets/text/start_ins.png", 177, 64};
	Meow::Renderer::Draw(start_instruction);
	Meow::Unit move_instruction{"../myGame/assets/text/move_ins.png", 64, 256};
	Meow::Renderer::Draw(move_instruction);
}

void MyGameApplication::DrawGameOver() {
	Meow::Unit game_over{"../myGame/assets/text/game_over.png", 230, 280};
	Meow::Renderer::Draw(game_over);
}

void MyGameApplication::KeyEventHandler(const Meow::KeyEvent& event) {
	if (event.GetKeyCode() == MEOW_KEY_W || event.GetKeyCode() == MEOW_KEY_UP) {
		if (event.GetKeyAction() == Meow::KeyEvent::KeyAction::PRESS) {
			player_movement.y += PLAYER_SPEED;
		} else if (event.GetKeyAction() == Meow::KeyEvent::KeyAction::RELEASE) {
			player_movement.y -= PLAYER_SPEED;
		}
	}
	if (event.GetKeyCode() == MEOW_KEY_A || event.GetKeyCode() == MEOW_KEY_LEFT) {
		if (event.GetKeyAction() == Meow::KeyEvent::KeyAction::PRESS) {
			player_movement.x -= PLAYER_SPEED;
		} else if (event.GetKeyAction() == Meow::KeyEvent::KeyAction::RELEASE) {
			player_movement.x += PLAYER_SPEED;
		}
	}
	if (event.GetKeyCode() == MEOW_KEY_S || event.GetKeyCode() == MEOW_KEY_DOWN) {
		if (event.GetKeyAction() == Meow::KeyEvent::KeyAction::PRESS) {
			player_movement.y -= PLAYER_SPEED;
		} else if (event.GetKeyAction() == Meow::KeyEvent::KeyAction::RELEASE) {
			player_movement.y += PLAYER_SPEED;
		}
	}
	if (event.GetKeyCode() == MEOW_KEY_D || event.GetKeyCode() == MEOW_KEY_RIGHT) {
		if (event.GetKeyAction() == Meow::KeyEvent::KeyAction::PRESS) {
			player_movement.x += PLAYER_SPEED;
		} else if (event.GetKeyAction() == Meow::KeyEvent::KeyAction::RELEASE) {
			player_movement.x -= PLAYER_SPEED;
		}
	}

	if (game_state == GameState::MAIN_MENU && event.GetKeyCode() == MEOW_KEY_SPACE) {
		ChangeGameState(GameState::GAME_PLAY);
	}
}