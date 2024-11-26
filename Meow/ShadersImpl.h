#pragma once

#include "pch.h"

namespace Meow {

class ShadersImpl {
public:
	virtual void LoadShaders(const std::string& vertexSFile, const std::string& fragmentSFile) = 0;
	virtual void Bind() const = 0;
	virtual void SetIntUniform(const std::string& uniformName, const std::vector<int>& values) const = 0;
	virtual void SetIntUniform(const std::string& uniformName, int value) const = 0;

	virtual ~ShadersImpl() {};
};

}