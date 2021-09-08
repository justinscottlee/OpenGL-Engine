#ifndef SHADER_H_
#define SHADER_H_
#include <string>

#include "GL/glew.h"

class Shader {
public:
    Shader(const std::string& file_name, GLenum type);
    ~Shader();
    GLuint GetId() { return id_; }
    GLenum GetType() { return type_; }
private:
    GLuint id_;
    GLenum type_;
};
#endif