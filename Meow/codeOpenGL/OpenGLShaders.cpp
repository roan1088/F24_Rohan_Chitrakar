#include "pch.h"
#include "OpenGLShaders.h"

#include "glad/glad.h"
#include "MeowUtilities.h"

namespace Meow {

OpenGLShaders::OpenGLShaders() {}

OpenGLShaders::OpenGLShaders(const std::string &vertexSFile, const std::string &fragmentSFile) {
	LoadShaders(vertexSFile, fragmentSFile);
}

void OpenGLShaders::LoadShaders(const std::string &vertexSFile, const std::string &fragmentSFile) {
	if (mShaders) {
		glDeleteProgram(mShaders);
	}

	std::string vertexSCode{ReadFile(vertexSFile)};
	const char *cVertexCode{vertexSCode.c_str()};
	unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &cVertexCode, NULL);
	glCompileShader(vertexShader);

	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		MEOW_ERROR("ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
	}

	std::string fragmentSCode{ReadFile(fragmentSFile)};
	const char *cFragmentCode{fragmentSCode.c_str()};
	unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &cFragmentCode, NULL);
	glCompileShader(fragmentShader);

	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success) {
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		MEOW_ERROR("ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
	}

	mShaders = glCreateProgram();
	glAttachShader(mShaders, vertexShader);
	glAttachShader(mShaders, fragmentShader);
	glLinkProgram(mShaders);

	glGetProgramiv(mShaders, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(mShaders, 512, NULL, infoLog);
		MEOW_ERROR("ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void OpenGLShaders::Bind() const {
	glUseProgram(mShaders);
}

void OpenGLShaders::SetIntUniform(const std::string &uniformName, const std::vector<int> &values) const {
	glUseProgram(mShaders);
	int location{glGetUniformLocation(mShaders, uniformName.c_str())};

	switch (values.size()) {
	case 1:
		glUniform1i(location, values[0]);
		break;
	case 2:
		glUniform2i(location, values[0], values[1]);
		break;
	case 3:
		glUniform3i(location, values[0], values[1], values[2]);
		break;
	case 4:
		glUniform4i(location, values[0], values[1], values[2], values[3]);
		break;
	default:
		MEOW_ERROR("Failed to set integer uniform, invalid size!");
		break;
	}
}

void OpenGLShaders::SetIntUniform(const std::string &uniformName, int value) const {
	glUseProgram(mShaders);
	int location{glGetUniformLocation(mShaders, uniformName.c_str())};
	glUniform1i(location, value);
}

OpenGLShaders::~OpenGLShaders() {
	if (mShaders) {
		glDeleteProgram(mShaders);
	}
}

std::string OpenGLShaders::ReadFile(const std::string &fileName) const {
	std::ifstream input{fileName};

	if (!input) {
		MEOW_ERROR("Failed to load shader, could not open file.");
	}

	std::string result, line;

	while (std::getline(input, line)) {
		result += line + '\n';
	}

	input.close();

	return result;
}

}