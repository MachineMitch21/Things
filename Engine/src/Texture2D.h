#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <GL/glew.h>

#include <string>

class Texture2D 
{
public:
    Texture2D();
    Texture2D(const Texture2D& oldTex2D);
    Texture2D(const std::string& file);
    ~Texture2D();

    void Bind(unsigned int unit = 0) const;
    void UnBind() const;

    inline int GetWidth() const { return _width; };
    inline int GetHeight() const { return _height; };

    void Load(const std::string& file);

private:
    unsigned int    _rendererID;
    std::string     _filePath;
    unsigned char*  _pixelBuffer;
    int             _width;
    int             _height;
    int             _bytesPerPixel;
};

#endif // TEXTURE2D_H