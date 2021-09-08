#include "window.h"

Window::Window(int width, int height, const std::string& title, bool vsync) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfw_window_ = glfwCreateWindow(1024, 768, title.c_str(), nullptr, nullptr);
    if (!glfw_window_) {
        glfwTerminate();
        exit(-1);
    }
    glfwMakeContextCurrent(glfw_window_);
    glfwSwapInterval(vsync ? 1 : 0);
}

Window::~Window() {
    glfwDestroyWindow(glfw_window_);
}

void Window::Update() {
    glfwGetFramebufferSize(glfw_window_, &width_, &height_);
    glViewport(0, 0, width_, height_);
    glfwSwapBuffers(glfw_window_);
    glfwPollEvents();
}