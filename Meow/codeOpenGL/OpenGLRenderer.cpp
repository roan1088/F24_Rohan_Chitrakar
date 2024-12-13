#include "pch.h"
#include "OpenGLRenderer.h"

#include "glad/glad.h"
#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "MeowWindow.h"

namespace Meow {

OpenGLRenderer::OpenGLRenderer() {
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD" << std::endl;
	}

	defaultShaders.LoadShaders(
		"../Meow/assets/shaders/defaultVertexShader.glsl",
		"../Meow/assets/shaders/defaultFragmentShader.glsl"
	);

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);

	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));
	glEnableVertexAttribArray(1);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGLRenderer::Draw(const Image &pic, int xCoord, int yCoord) {
	defaultShaders.Bind();
	defaultShaders.SetIntUniform(
		"screenDim",
		{MeowWindow::GetWindow()->GetWidth(), MeowWindow::GetWindow()->GetHeight()}
	);
	Draw(pic, xCoord, yCoord, defaultShaders);
}

void OpenGLRenderer::Draw(const Image &pic, int xCoord, int yCoord, const Shaders &shaders) {
	float vertices[] = {
		xCoord, yCoord, 0.0f, 0.0f,
		xCoord, yCoord + pic.GetHeight(), 0.0f, 1.0f,
		xCoord + pic.GetWidth(), yCoord + pic.GetHeight(), 1.0f, 1.0f,
		xCoord + pic.GetWidth(), yCoord, 1.0f, 0.0f
	};
	unsigned int indices[] = {
		0, 1, 2,
		0, 2, 3
	};

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glBindVertexArray(VAO);
	pic.Bind();
	shaders.Bind();
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void OpenGLRenderer::ClearScreen() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

}