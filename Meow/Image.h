#pragma once

#include "pch.h"
#include "MeowUtilities.h"
#include "ImageImpl.h"

namespace Meow {

class MEOW_API Image {
public:
	Image();
	Image(const std::string& filePath);

	void LoadImage(const std::string& filePath);

	bool HasImage() const;
	int GetWidth() const;
	int GetHeight() const;

private:
	void Bind() const;

	std::unique_ptr<ImageImpl> implementation;

	friend class Renderer;
};

}