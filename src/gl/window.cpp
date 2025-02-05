#include "window.hpp"

#include <gl/gl.h>

namespace gl {

Window::Window(int width, int height) {

    glfwInit();

    GL_INIT_CONTEXT();

    this->wn = glfwCreateWindow(
        width, height, "Game 2021-22", nullptr, nullptr
    );
    glfwMakeContextCurrent(this->wn);
    gladLoadGL();
    glfwShowWindow(this->wn);
    // Test - apocalyptic gray
    glClearColor(0.6f, 0.6f, 0.6f, 1.0f);

}

Window::~Window() {

    glfwDestroyWindow(this->wn);
    glfwTerminate();

}

bool Window::is_open() {
    return !glfwWindowShouldClose(wn);
}

}
