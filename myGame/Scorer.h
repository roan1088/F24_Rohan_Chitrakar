#pragma once

#include "Meow.h"

class Scorer {
public:
	void Reset();
	void AddScore(int amount = 1);
	int GetScore();

	void DrawScore(int x = 720, int y = 520);

private:
	int score{0};
};