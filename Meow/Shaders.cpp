#include "pch.h"
#include "Shaders.h"
#include "codeOpenGL/OpenGLShaders.h"

namespace Meow {

Shaders::Shaders() {
	#ifdef MEOW_OPENGL
	implementation = std::unique_ptr<ShadersImpl>{new OpenGLShaders};
	#else
	#only_opengl_is_supported_so_far
	#endif
}

Shaders::Shaders(const std::string& vertexSFile, const std::string& fragmentSFile) {
	#ifdef MEOW_OPENGL
	implementation = std::unique_ptr<ShadersImpl>{new OpenGLShaders(vertexSFile, fragmentSFile)};
	#else
	#only_opengl_is_supported_so_far
	#endif
}

void Shaders::LoadShaders(const std::string& vertexSFile, const std::string& fragmentSFile) {
	implementation->LoadShaders(vertexSFile, fragmentSFile);
}

void Shaders::Bind() const {
	implementation->Bind();
}

void Shaders::SetIntUniform(const std::string& uniformName, const std::vector<int>& values) const {
	implementation->SetIntUniform(uniformName, values);
}

void Shaders::SetIntUniform(const std::string& uniformName, int value) const {
	implementation->SetIntUniform(uniformName, value);
}

}