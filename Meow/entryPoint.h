#pragma once

#define MEOW_GAME_START(className) \
int main() {\
	className game;\
	game.Run();\
	return 0;\
}
