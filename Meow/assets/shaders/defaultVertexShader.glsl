#version 330 core

layout (location = 0) in vec2 aPos;
layout (location = 1) in vec2 aTexCoord;
out vec2 v_texCoord;
uniform ivec2 screenDim;

void main() {
	gl_Position = vec4(2*aPos.x/screenDim.x - 1, 2*aPos.y/screenDim.y - 1, 0.0, 1.0);
	v_texCoord = aTexCoord;
}