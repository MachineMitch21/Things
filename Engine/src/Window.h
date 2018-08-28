
#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include <GLFW/glfw3.h>

#include "Input.h"

using namespace antisocial::input;

class Window 
{
public:
    Window(const std::string& title, int width, int height);
    ~Window();

    bool IsClosed();
    void Update();
    void Close();

    void VerifyFrameBufferSize();

    void ChangeGLFWwindow(GLFWwindow* nWindow);
    void ChangeTitle(const std::string& nTitle);

    inline GLFWwindow*          GetGlfwWindow() const { return _window; };
    inline const std::string&   GetTitle()      const { return _title;  };
    inline int                  GetWidth()      const { return _width;  };
    inline int                  GetHeight()     const { return _height; };

private:
    friend void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    friend void refresh_callback(GLFWwindow* window);
    friend void error_callback(int error, const char* description);
    bool Init();

private:
    GLFWwindow*     _window;

    std::string     _title;
    int             _height;
    int             _width;
};

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void refresh_callback(GLFWwindow* window);
void error_callback(int error, const char* description);

#endif // WINDOW_H