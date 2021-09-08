#ifndef SHADER_PROGRAM_H_
#define SHADER_PROGRAM_H_
#include <vector>

#include "GL/glew.h"

class ShaderProgram {
public:
    ShaderProgram(const std::vector<GLuint>& shaders);
    ~ShaderProgram();
    inline void Start() { glUseProgram(id_); }
    inline void Stop() { glUseProgram(0); }
private:
    GLuint id_;
    std::vector<GLuint> shaders_;
};
#endif