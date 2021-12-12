#pragma once

#include <glad/glad.h>
#include "VBO.h"

class VAO {
public:
	VAO();

	GLuint m_ID;

	void LinkAttrib(VBO VBO, GLuint layout, GLuint numCompontents, GLenum type, GLsizeiptr stride, void* offset);
	
	void Bind(); 
	void Unbind();
	void Delete();

};