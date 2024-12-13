#pragma once

#include "pch.h"
#include "MeowUtilities.h"
#include "RendererImpl.h"
#include "Image.h"
#include "Shaders.h"
#include "Unit.h"

namespace Meow {

class MEOW_API Renderer {
public:
	static void Init();

	static void Draw(const Image& pic, int xCoord, int yCoord);
	static void Draw(const Image& pic, int xCoord, int yCoord, const Shaders& shaders);
	static void Draw(const Unit& unit);
	static void Draw(const Unit& unit, const Shaders& shaders);

	static void ClearScreen();

private:
	Renderer();

	std::unique_ptr<RendererImpl> implementation;
	inline static std::unique_ptr<Renderer> instance;
};

}