#pragma once

#include "pch.h"
#include "MeowUtilities.h"
#include "Image.h"

namespace Meow {

class MEOW_API Unit {
public:
	Unit(const std::string& fileName, int xCoord, int yCoord, bool visible = true);

	int GetWidth() const;
	int GetHeight() const;
	int GetXCoord() const;
	int GetYCoord() const;
	void SetCoords(int x, int y);
	void UpdateXCoord(int amount);
	void UpdateYCoord(int amount);

	bool isVisible() const;
	void SetVisibility(bool visibility);

private:
	Image mImage;
	int mXCoord{0};
	int mYCoord{0};
	bool mIsVisible{true};

	friend bool MEOW_API UnitsOverlap(const Unit& a, const Unit& b);
	friend class Renderer;
};

bool MEOW_API UnitsOverlap(const Unit& a, const Unit& b);

}