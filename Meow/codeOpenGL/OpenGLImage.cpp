#include "pch.h"
#include "OpenGLImage.h"

#include "glad/glad.h"
#include "stb_image.h"
#include "MeowUtilities.h"

namespace Meow {
OpenGLImage::OpenGLImage() {}

OpenGLImage::OpenGLImage(const std::string &filePath) {
	LoadImage(filePath);
}

void OpenGLImage::LoadImage(const std::string &filePath) {
	if (mImage) {
		glDeleteTextures(1, &mImage);
	}

	glGenTextures(1, &mImage);
	glBindTexture(GL_TEXTURE_2D, mImage);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	stbi_set_flip_vertically_on_load(true);
	int nrChannels{0};
	unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);

	if (data) {
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		MEOW_ERROR("Failed to load texture");
	}
	stbi_image_free(data);
}

bool OpenGLImage::HasImage() const {
	return mImage;
}

int OpenGLImage::GetWidth() const {
	return width;
}

int OpenGLImage::GetHeight() const {
	return height;
}

void OpenGLImage::Bind() const {
	glBindTexture(GL_TEXTURE_2D, mImage);
}

OpenGLImage::~OpenGLImage() {
	if (mImage) {
		glDeleteTextures(1, &mImage);
	}
}

}