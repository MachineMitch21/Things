
#ifndef SHADER_H
#define SHADER_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <GL/glew.h>

#define ERR_LOG 512

class Shader
{
public:
    /*
    Creates an empty program object and stores a handle to it
    in the _handle variable. If you do not pass in a vertex or fragment
    shader their values will be set to -1.
    */
    Shader();
    //Loads shaders from file and sends them to newly created program object
    Shader(const std::string& vert, const std::string& frag);
    ~Shader();

    //Tells GL to use the current _handle as shader program.
    void Bind() const;
    //Tells GL to stop using currently binded shader program.
    void UnBind() const;

    inline bool IsBound() const { return _isBound; };

    //Returns _handle variable containing a handle to current shader program
    GLuint& GetProgram();
    //Loads and compiles shader files.
    void SubmitShaderFile(const std::string& file, GLenum type);

    /*
    Iterates through _shaders map and attatches all the shader objects
    to the shader program referenced by _handle. This should only be called
    if every shader type needed for the shader program has been provided.
    */
    bool LinkProgram();

    /*
    Setting uniform shader variables by type. Pass in the name of the
    varible you wish to change and the value it is to be changed to.
    */
    void SetMatrix4(const std::string& name, const float* v);
    void SetMatrix3(const std::string& name, const float* v);
    void SetVector2(const std::string& name, float v1, float v2);
    void SetVector3(const std::string& name, float v1, float v2, float v3);
    void SetVector4(const std::string& name, float v1, float v2, float v3, float v4);
    void SetFloat(const std::string& name, float v);
    void SetBool(const std::string& name, bool v);
    void SetInteger(const std::string& name, int v);
    void SetUInteger(const std::string& name, unsigned int v);

    void                GetMatrix4(const std::string& name, float* elements, int* err);
    void                GetMatrix3(const std::string& name, float* elements, int* err);
    std::vector<float>  GetVector2(const std::string& name, int* err);
    std::vector<float>  GetVector3(const std::string& name, int* err);
    std::vector<float>  GetVector4(const std::string& name, int* err);
    float               GetFloat(const std::string& name, int* err);
    bool                GetBool(const std::string& name, int* err);
    int                 GetInteger(const std::string& name, int* err);
    unsigned int        GetUInteger(const std::string& name, int* err);

private:
    //Initializes _shaders map
    void init_shader_map();

    /*
    Move provided source code into shader and compiles it.
    returns handle to shader object.
    */
    GLuint compile_shader(const std::string& shader_src, GLenum shader_type);

    //Loads shader source code from file and returns it as a string.
    std::string load_shader(const std::string& filename);

private:
    std::map<GLenum, GLuint> 	_shaders;
    GLint 						_success;
    GLuint 						_handle;
    GLchar 						_errLog[ERR_LOG];
    bool                        _isBound;
};

#endif // SHADER_H
