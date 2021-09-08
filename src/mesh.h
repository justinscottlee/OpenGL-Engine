#ifndef MESH_H_
#define MESH_H_
#include <vector>

#include "GL/glew.h"
#include "vector3.h"

class Mesh {
public:
    std::vector<Vector3> vertices_;
    std::vector<GLuint> indices_;
    Mesh(const std::vector<Vector3>& vertices, const std::vector<GLuint>& indices) : vertices_(vertices), indices_(indices) {}
    GLuint GenerateVao();
private:
    GLuint GenerateIndicesVbo();
    GLuint GenerateVerticesVbo();
};
#endif