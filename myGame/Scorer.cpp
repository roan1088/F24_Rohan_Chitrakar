#include "Scorer.h"

void Scorer::Reset() {
	score = 0;
}

void Scorer::AddScore(int amount) {
	score += amount;
}

int Scorer::GetScore() {
	return score;
}