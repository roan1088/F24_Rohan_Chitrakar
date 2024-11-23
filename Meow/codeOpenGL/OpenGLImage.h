#pragma once

#include "../ImageImpl.h"

namespace Meow {

class OpenGLImage : public ImageImpl {
public:
	OpenGLImage();
	OpenGLImage(const std::string& filePath);

	virtual void LoadImage(const std::string& filePath) override;

	virtual bool HasImage() const override;
	virtual int GetWidth() const override;
	virtual int GetHeight() const override;

	virtual void Bind() const override;

	~OpenGLImage();

private:
	unsigned int mImage{0};
	int width{0}, height{0};
};

}