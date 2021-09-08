#include "shader_program.h"

#include <iostream>

ShaderProgram::ShaderProgram(const std::vector<GLuint>& shaders) : id_(glCreateProgram()), shaders_(shaders) {
    for (GLuint shader : shaders_) {
        glAttachShader(id_, shader);
    }
    glLinkProgram(id_);
}

ShaderProgram::~ShaderProgram() {
    for (GLuint shader : shaders_) {
        glDetachShader(id_, shader);
    }
    glDeleteProgram(id_);
}