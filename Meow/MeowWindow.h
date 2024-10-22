#pragma once

#include "pch.h"
#include "WindowImpl.h"
#include "MeowUtilities.h"

namespace Meow {

class MEOW_API MeowWindow {
public:
	MeowWindow();

	void CreateWindow(int width, int height, std::string windowName);
	int GetWidth() const;
	int GetHeight() const;

private:
	WindowImpl* implementation{nullptr};
};

}