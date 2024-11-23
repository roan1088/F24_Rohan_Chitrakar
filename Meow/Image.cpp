#include "pch.h"
#include "Image.h"
#include "codeOpenGL/OpenGLImage.h"

namespace Meow {

Image::Image() {
	#ifdef MEOW_OPENGL
	implementation = std::unique_ptr<ImageImpl>{new OpenGLImage};
	#else
	#only_opengl_is_supported_so_far
	#endif
}

Image::Image(const std::string& filePath) {
	#ifdef MEOW_OPENGL
	implementation = std::unique_ptr<ImageImpl>{new OpenGLImage(filePath)};
	#else
	#only_opengl_is_supported_so_far
	#endif
}

void Image::LoadImage(const std::string& filePath) {
	implementation->LoadImage(filePath);
}

bool Image::HasImage() const {
	return implementation->HasImage();
}
int Image::GetWidth() const {
	return implementation->GetWidth();
}
int Image::GetHeight() const {
	return implementation->GetHeight();
}

void Image::Bind() const {
	implementation->Bind();
}

}