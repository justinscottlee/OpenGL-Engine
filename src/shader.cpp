#include "shader.h"

#include <string.h>
#include <fstream>
#include <iostream>
#include <sstream>

Shader::Shader(const std::string& file_path, GLenum type) : id_(glCreateShader(type)), type_(type) {
    std::ifstream file(file_path);
    if (!file.is_open()) {
        std::cerr << "Couldn't open shader path '" << file_path << "'." << std::endl;
        exit(-1);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    file.close();
    std::string str = buffer.str();
    const GLchar* shader_source = str.c_str();
    glShaderSource(id_, 1, &shader_source, nullptr);
    glCompileShader(id_);
}

Shader::~Shader() {
    glDeleteShader(id_);
}