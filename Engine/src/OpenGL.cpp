
#include "OpenGL.h"

OpenGL::OpenGL()
{

}

OpenGL::~OpenGL()
{

}

void OpenGL::Clear(float r, float g, float b, float a)
{
    glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    glClearColor(r, g, b, a);
}