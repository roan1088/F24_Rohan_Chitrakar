#pragma once

#include "pch.h"

namespace Meow {

class ImageImpl {
public:
	virtual void LoadImage(const std::string& filePath) = 0;

	virtual bool HasImage() const = 0;
	virtual int GetWidth() const = 0;
	virtual int GetHeight() const = 0;

	virtual void Bind() const = 0;

	virtual ~ImageImpl() {};
};

}