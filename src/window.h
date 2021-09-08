#ifndef WINDOW_H_
#define WINDOW_H_
#include <string>

#include "GLFW/glfw3.h"

class Window {
public:
    Window(int width, int height, const std::string& title, bool vsync);
    ~Window();
    void Update();
    bool ShouldClose() { return glfwWindowShouldClose(glfw_window_); }
private:
    GLFWwindow* glfw_window_;
    int width_, height_;
};
#endif