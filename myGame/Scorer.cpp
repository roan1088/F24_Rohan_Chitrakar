#include "Scorer.h"
#include <string>

void Scorer::Reset() {
	score = 0;
}

void Scorer::AddScore(int amount) {
	score += amount;
}

int Scorer::GetScore() {
	return score;
}

void Scorer::DrawScore(int x, int y) {
	int num = score;

	do {
		int digit = num % 10;
		std::string filepath = "../myGame/assets/numbers/num" + std::to_string(digit) + ".png";
		Meow::Unit ui{filepath, x, y};
		Meow::Renderer::Draw(ui);
		x -= 40;
		num /= 10;
	} while (num);
}
