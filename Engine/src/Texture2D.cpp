#include "Texture2D.h"

#include "stb_image/stb_image.h"

#include <cstdlib>

Texture2D::Texture2D()
    :   _rendererID(0),
        _filePath("NULL"),
        _pixelBuffer(nullptr),
        _width(0),
        _height(0),
        _bytesPerPixel(0)
{
    
}

Texture2D::Texture2D(const Texture2D& oldTex2D)
{
    _rendererID     = oldTex2D._rendererID;
    _filePath       = oldTex2D._filePath;
    _pixelBuffer    = oldTex2D._pixelBuffer;
    _width          = oldTex2D._width;
    _height         = oldTex2D._height;
    _bytesPerPixel  = oldTex2D._bytesPerPixel;
}

Texture2D::Texture2D(const std::string& file) 
    :   _rendererID(0),
        _filePath(file),
        _pixelBuffer(nullptr),
        _width(0),
        _height(0),
        _bytesPerPixel(0)
{
    Load(file);
}

Texture2D::~Texture2D() 
{
    if (_rendererID)
    {
        glDeleteTextures(1, &_rendererID);
        _rendererID = 0;
    }

    if (_pixelBuffer)
    {
        stbi_image_free(_pixelBuffer);
    }
}

void Texture2D::Bind(unsigned int unit) const
{
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, _rendererID);
}

void Texture2D::UnBind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::Load(const std::string& file)
{
    if (_rendererID == 0)
    {
        glGenTextures(1, &_rendererID);
    }

    stbi_set_flip_vertically_on_load(1);
    _pixelBuffer = stbi_load(file.c_str(), &_width, &_height, &_bytesPerPixel, 4);

    if (_pixelBuffer)
    {
        printf("Texture loaded successfully -- {%s}\n", file.c_str());
        _filePath = file;
    }
    else 
    {
        printf("Texture failed to load -- {%s}\n", file.c_str());
        return;
    }
    
    glBindTexture(GL_TEXTURE_2D, _rendererID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glGenerateMipmap(GL_TEXTURE_2D);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _pixelBuffer);
    glBindTexture(GL_TEXTURE_2D, 0);
}
