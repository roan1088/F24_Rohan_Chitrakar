#pragma once

#include "../ShadersImpl.h"

namespace Meow {

class OpenGLShaders : public ShadersImpl {
public:
	OpenGLShaders();
	OpenGLShaders(const std::string& vertexSFile, const std::string& fragmentSFile);

	virtual void LoadShaders(const std::string& vertexSFile, const std::string& fragmentSFile) override;
	virtual void Bind() const override;
	virtual void SetIntUniform(const std::string& uniformName, const std::vector<int>& values) const override;
	virtual void SetIntUniform(const std::string& uniformName, int value) const override;

	~OpenGLShaders();
private:
	unsigned int mShaders{0};

	std::string ReadFile(const std::string& fileName) const;
};

}