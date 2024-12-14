#include "MyGameApplication.h"

#include <cstdlib>
#include <ctime>

void MyGameApplication::Initialize() {
	MEOW_LOG("Starting...");
	srand(time(nullptr));

	SetKeyEventHandler([this](const Meow::KeyEvent& event) {KeyEventHandler(event);});

	SetUpBackground();
}

void MyGameApplication::Update() {
	DrawBackground();
	Meow::Renderer::Draw(player);

	MoveBackground();
	UpdatePlayerPosition();
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
}