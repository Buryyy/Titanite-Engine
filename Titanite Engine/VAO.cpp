#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &m_ID);
}

void VAO::LinkAttrib(VBO VBO, GLuint layout, GLuint numComponents, 
	GLenum type, GLsizeiptr stride, void* offset) {
	VBO.OnBind();
	glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, stride, offset); 
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

void VAO::Bind() {
	glBindVertexArray(m_ID);
}

void VAO::Unbind(){
	glBindVertexArray(0);
}

void VAO::Delete() {
	glDeleteVertexArrays(1, &m_ID);
}