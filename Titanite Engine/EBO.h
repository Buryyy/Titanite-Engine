#pragma once

#include <glad/glad.h>

class EBO {

public:

	EBO(GLuint* indices, GLsizeiptr size);
	GLuint m_ID;

	void OnBind();
	void Unbind();
	void OnDelete();
};

