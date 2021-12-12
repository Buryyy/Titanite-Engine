#pragma once

#include <glad/glad.h>

class VBO {

public:

	VBO(GLfloat* vertices, GLsizeiptr size);
	GLuint m_ID;

	void OnBind();
	void Unbind();
	void OnDelete();
};

