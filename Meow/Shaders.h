#pragma once

#include "pch.h"
#include "MeowUtilities.h"
#include "ShadersImpl.h"

namespace Meow {

class MEOW_API Shaders {
public:
	Shaders();
	Shaders(const std::string& vertexSFile, const std::string& fragmentSFile);

	void LoadShaders(const std::string& vertexSFile, const std::string& fragmentSFile);
	void Bind() const;
	void SetIntUniform(const std::string& uniformName, const std::vector<int>& values) const;
	void SetIntUniform(const std::string& uniformName, int value) const;

private:
	std::unique_ptr<ShadersImpl> implementation;
};

}