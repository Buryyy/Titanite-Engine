#include "Shader.h"

std::string get_file_contents(const char* fileName) {
	std::ifstream in(fileName, std::ios::binary);
	if (in) {
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return (contents);
	}
	throw (errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) {
	std::string vertexCode = get_file_contents(vertexFile);
	std::string fragmentCode = get_file_contents(fragmentFile);

	const char* vertSource = vertexCode.c_str();
	const char* fragSource = fragmentCode.c_str();
	//Create & compile vert shader
	GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertShader, 1, &vertSource, NULL);
	glCompileShader(vertShader);

	//Create & compile frag shader
	GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragShader, 1, &fragSource, NULL);
	glCompileShader(fragShader);

	m_ID = glCreateProgram(); //Appoint id of the shader from the glCreateProgram function that returns GLuint
	glAttachShader(m_ID, vertShader);
	glAttachShader(m_ID, fragShader);

	glLinkProgram(m_ID);

	glDeleteShader(vertShader);
	glDeleteShader(fragShader);
}

void Shader::OnDelete()
{
	glDeleteProgram(m_ID);
}

void Shader::OnActivate() {
	glUseProgram(m_ID);

}
