#pragma once

#include "../RendererImpl.h"

namespace Meow {

class OpenGLRenderer : public RendererImpl {
public:
	OpenGLRenderer();

	virtual void Draw(const Image& pic, int xCoord, int yCoord) override;
	virtual void Draw(const Image& pic, int xCoord, int yCoord, const Shaders& shaders) override;

	virtual void ClearScreen() override;

private:
	unsigned int VBO{0}, VAO{0}, EBO{0};

	Shaders defaultShaders;
};

}