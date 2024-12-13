#include "pch.h"
#include "Renderer.h"

#include "codeOpenGL/OpenGLRenderer.h"

namespace Meow {

Renderer::Renderer() {
	#ifdef MEOW_OPENGL
	implementation = std::unique_ptr<RendererImpl>{new OpenGLRenderer};
	#else
	#only_opengl_is_supported_so_far
	#endif
}

void Renderer::Init() {
	if (instance == nullptr) {
		instance = std::unique_ptr<Renderer>(new Renderer);
	}
}

void Renderer::Draw(const Image& pic, int xCoord, int yCoord) {
	instance->implementation->Draw(pic, xCoord, yCoord);
}

void Renderer::Draw(const Image& pic, int xCoord, int yCoord, const Shaders& shaders) {
	instance->implementation->Draw(pic, xCoord, yCoord, shaders);
}

void Renderer::Draw(const Unit& unit) {
	if(unit.mIsVisible) {
		Draw(unit.mImage, unit.mXCoord, unit.mYCoord);
	}
}

void Renderer::Draw(const Unit& unit, const Shaders& shaders) {
	if(unit.mIsVisible) {
		Draw(unit.mImage, unit.mXCoord, unit.mYCoord, shaders);
	}
}

void Renderer::ClearScreen() {
	instance->implementation->ClearScreen();
}

}