#pragma once

#include "Meow.h"

class Scorer {
public:
	void Reset();
	void AddScore(int amount = 1);
	int GetScore();

private:
	int score{0};
};