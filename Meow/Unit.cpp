#include "pch.h"
#include "Unit.h"

namespace Meow {

Unit::Unit(const std::string &fileName, int xCoord, int yCoord, bool visible) :
mImage{fileName}, mXCoord{xCoord}, mYCoord{yCoord}, mIsVisible{visible} {}

int Unit::GetWidth() const {
	return mImage.GetWidth();
}

int Unit::GetHeight() const {
	return mImage.GetHeight();
}

int Unit::GetXCoord() const {
	return mXCoord;
}

int Unit::GetYCoord() const {
	return mYCoord;
}

void Unit::SetCoords(int x, int y) {
	mXCoord = x;
	mYCoord = y;
}

void Unit::UpdateXCoord(int amount) {
	mXCoord += amount;
}

void Unit::UpdateYCoord(int amount) {
	mYCoord += amount;
}

bool Unit::isVisible() const {
	return mIsVisible;
}

void Unit::SetVisibility(bool visibility) {
	mIsVisible = visibility;
}

bool MEOW_API UnitsOverlap(const Unit &a, const Unit &b) {
	int left_a{a.mXCoord};
	int right_a{a.mXCoord + a.GetWidth()};
	int left_b{b.mXCoord};
	int right_b{b.mXCoord + b.GetWidth()};

	bool x_intersection = (left_a <= left_b && left_b <= right_a) || (left_b <= left_a && left_a <= right_b);

	int bot_a{a.mYCoord};
	int top_a{a.mYCoord + a.GetHeight()};
	int bot_b{b.mYCoord};
	int top_b{b.mYCoord + b.GetHeight()};

	bool y_intersection = (bot_a <= bot_b && bot_b <= top_a) || (bot_b <= bot_a && bot_a <= top_b);

	return x_intersection && y_intersection;
}

}