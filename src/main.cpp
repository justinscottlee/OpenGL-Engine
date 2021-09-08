#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "window.h"
#include "mesh.h"
#include "shader_program.h"
#include "shader.h"

int main() {
    if (!glfwInit()) {
        return -1;
    }

    Window window = Window(1024, 768, "Engine Window", false);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        glfwTerminate();
        return -1;
    }

    //start
    Vector3 aaa(-0.5f, -0.5f, -0.5f);
    Vector3 aaA(-0.5f, -0.5f, 0.5f);
    Vector3 aAa(-0.5f, 0.5f, -0.5f);
    Vector3 aAA(-0.5f, 0.5f, 0.5f);
    Vector3 Aaa(0.5f, -0.5f, -0.5f);
    Vector3 AaA(0.5f, -0.5f, 0.5f);
    Vector3 AAa(0.5f, 0.5f, -0.5f);
    Vector3 AAA(0.5f, 0.5f, 0.5f);

    Mesh mesh({aaa, aaA, aAa, aAA, Aaa, AaA, AAa, AAA}, {1, 0, 2, 1, 2, 3, 1, 5, 4, 1, 0, 4, 5, 7, 6, 5, 4, 6, 2, 3, 6, 3, 6, 7, 1, 5, 3, 5, 7, 3, 0, 2, 4, 2, 6, 4});
    GLuint mesh_vao = mesh.GenerateVao();

    Shader vertex_shader("vertshader.glsl", GL_VERTEX_SHADER);
    Shader fragment_shader("fragshader.glsl", GL_FRAGMENT_SHADER);
    ShaderProgram shader_program({vertex_shader.GetId(), fragment_shader.GetId()});

    glClearColor(0.8f, 0.9f, 1.0f, 1.0f);
    float angle = 0;
    while (!window.ShouldClose()) {
        glClear(GL_COLOR_BUFFER_BIT);

        //start
        shader_program.Start();
        glBindVertexArray(mesh_vao);
        glEnableVertexAttribArray(0);
        glDrawElements(GL_TRIANGLES, mesh.indices_.size(), GL_UNSIGNED_INT, nullptr);
        glDisableVertexAttribArray(0);
        shader_program.Stop();
        //end

        window.Update();
    }

    glfwTerminate();
    return 0;
}