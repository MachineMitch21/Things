
#include <GL/glew.h>
#include "Window.h"

#include <cstdio>




// glfw callbacks 
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    Window* win = (Window*) glfwGetWindowUserPointer(window);
    win->_width = width;
    win->_height = height;

    glViewport(0, 0, width, height);
}

void refresh_callback(GLFWwindow* window)
{
    glfwSwapBuffers(window);
}

void error_callback(int error, const char* description)
{
    printf("Glfw error -- { %d } \n%s", error, description);
}




Window::Window(const std::string& title, int width, int height)
    :   _title(title),
        _width(width),
        _height(height)
{
    if (!Init())
    {
        printf("OpenGL initialization has failed");
        glfwTerminate();
    }
}

Window::~Window()
{
    glfwTerminate();
}

bool Window::Init()
{
    if (!glfwInit())
    {
        printf("GLFW ERROR -- Could not initialize GLFW\n");
        return false;
    }

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);

#ifdef _APPLE_
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
#endif // _APPLE_

#ifdef _DEBUG
    printf(" -- DEBUG MODE -- \n");
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#else
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_FALSE);
#endif // _DEBUG

    _window = glfwCreateWindow(_width, _height, _title.c_str(), NULL, NULL);

    if (!_window)
    {
        printf("GLFW ERROR -- Could create GLFWwindow*\n");
        return false;
    }

    glfwMakeContextCurrent(_window);

    glfwSetWindowUserPointer(_window, this);

    glfwGetFramebufferSize(_window, &_width, &_height);
    glViewport(0, 0, _width, _height);

    glfwSetWindowAspectRatio(_window, 16, 9);

    glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);
    glfwSetWindowRefreshCallback(_window, refresh_callback);
    glfwSetErrorCallback(error_callback);

    return true;
}

bool Window::IsClosed() 
{
    Input::UpdateStates();

    return glfwWindowShouldClose(_window);
}

void Window::Close()
{
    glfwSetWindowShouldClose(_window, GLFW_TRUE);
}

void Window::Update()
{
    glfwMakeContextCurrent(_window);
    glfwSetWindowUserPointer(_window, this);

    glfwSwapBuffers(_window);
}

void Window::VerifyFrameBufferSize()
{
    glfwMakeContextCurrent(_window);
    glfwSetWindowUserPointer(_window, this);
    glfwGetFramebufferSize(_window, &_width, &_height);
    glViewport(0, 0, _width, _height);
}