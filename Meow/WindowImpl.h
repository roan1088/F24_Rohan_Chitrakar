#pragma once

#include "pch.h"

namespace Meow {

class WindowImpl {
public:
	virtual void Create(int width, int height, std::string windowName) = 0;
	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;
};

}