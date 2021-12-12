#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_file_contents(const char* fileName);

class Shader {
public:
	Shader(const char* vertexFile, const char* fragmentFile);

	GLuint m_ID;
	
	void OnActivate();
	void OnDelete();
};

