#pragma once

#include "Image.h"
#include "Shaders.h"

namespace Meow {

class RendererImpl {
public:
	virtual void Draw(const Image& pic, int xCoord, int yCoord) = 0;
	virtual void Draw(const Image& pic, int xCoord, int yCoord, const Shaders& shaders) = 0;

	virtual void ClearScreen() = 0;

	virtual ~RendererImpl() {};
};

}