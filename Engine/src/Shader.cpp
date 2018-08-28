#include "Shader.h"

Shader::Shader()
	:	_handle(glCreateProgram())
{
	init_shader_map();
}

Shader::Shader(const std::string& vert, const std::string& frag)
	:	_handle(glCreateProgram())
{
 	init_shader_map();

	SubmitShaderFile(vert, GL_VERTEX_SHADER);
	SubmitShaderFile(frag, GL_FRAGMENT_SHADER);
	LinkProgram();
}

void Shader::SubmitShaderFile(const std::string& file, GLenum type)
{
	std::string shaderSrc = load_shader(file);
	GLuint shaderID = compile_shader(shaderSrc, type);
	_shaders.at(type) = shaderID;
}

void Shader::Bind() const
{
	glUseProgram(_handle);
}

void Shader::UnBind() const
{
	glUseProgram(0);
}

void Shader::SetMatrix4(const std::string& name, const float* v)
{
	GLuint uniformLocation = glGetUniformLocation(_handle, name.c_str());
	glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, v);
}

void Shader::SetMatrix3(const std::string& name, const float* v)
{
    GLuint uniformLocation = glGetUniformLocation(_handle, name.c_str());
    glUniformMatrix3fv(uniformLocation, 1, GL_FALSE, v);
}

void Shader::SetVector2(const std::string& name, float v1, float v2)
{
	GLuint uniformLocation = glGetUniformLocation(_handle, name.c_str());
	glUniform2f(uniformLocation, v1, v2);
}

void Shader::SetVector3(const std::string& name, float v1, float v2, float v3)
{
	GLuint uniformLocation = glGetUniformLocation(_handle, name.c_str());
	glUniform3f(uniformLocation, v1, v2, v3);
}

void Shader::SetVector4(const std::string& name, float v1, float v2, float v3, float v4)
{
	GLuint uniformLocation = glGetUniformLocation(_handle, name.c_str());
	glUniform4f(uniformLocation, v1, v2, v3, v4);
}

void Shader::SetFloat(const std::string& name, float v)
{
	GLuint uniformLocation = glGetUniformLocation(_handle, name.c_str());
	glUniform1f(uniformLocation, v);
}

void Shader::SetBool(const std::string& name, bool v)
{
	GLuint uniformLocation = glGetUniformLocation(_handle, name.c_str());
	glUniform1i(uniformLocation, v);
}

void Shader::SetInteger(const std::string& name, int v)
{
	GLuint uniformLocation = glGetUniformLocation(_handle, name.c_str());
	glUniform1i(uniformLocation, v);
}

void Shader::SetUInteger(const std::string& name, unsigned int v)
{
	GLuint uniformLocation = glGetUniformLocation(_handle, name.c_str());
	glUniform1ui(uniformLocation, v);
}

void Shader::GetMatrix4(const std::string& name, float* elements, int* err)
{
    *err = glGetUniformLocation(_handle, name.c_str());

    if (*err != -1)
    {
        glGetUniformfv(_handle, *err, elements);
    }
}

void Shader::GetMatrix3(const std::string& name, float* elements, int* err)
{
    *err = glGetUniformLocation(_handle, name.c_str());

    if (*err != -1)
    {
        glGetUniformfv(_handle, *err, elements);
    }
}

std::vector<float>  Shader::GetVector2(const std::string& name, int* err)
{
    std::vector<float> vec2;
    vec2.reserve(2);

    *err = glGetUniformLocation(_handle, name.c_str());

    if (*err != -1)
    {
        glGetUniformfv(_handle, *err, vec2.data());
    }

    return vec2;
}

std::vector<float>  Shader::GetVector3(const std::string& name, int* err)
{
    std::vector<float> vec3;
    vec3.reserve(3);

    *err = glGetUniformLocation(_handle, name.c_str());

    if (*err != -1)
    {
        glGetUniformfv(_handle, *err, vec3.data());
    }

    return vec3;
}

std::vector<float>  Shader::GetVector4(const std::string& name, int* err)
{
    std::vector<float> vec4;
    vec4.reserve(4);

    *err = glGetUniformLocation(_handle, name.c_str());

    if (*err != -1)
    {
        glGetUniformfv(_handle, *err, vec4.data());
    }

    return vec4;
}

float Shader::GetFloat(const std::string& name, int* err)
{
    float value;

    *err = glGetUniformLocation(_handle, name.c_str());

    if (*err != -1)
    {
        glGetUniformfv(_handle, *err, &value);
    }

    return value;
}

bool Shader::GetBool(const std::string& name, int* err)
{
    bool value;

    *err = glGetUniformLocation(_handle, name.c_str());

    if (*err != -1)
    {
        glGetUniformiv(_handle, *err, (int*) &value);
    }

    return value;
}

int Shader::GetInteger(const std::string& name, int* err)
{
    int value;

    *err = glGetUniformLocation(_handle, name.c_str());

    if (*err != -1)
    {
        glGetUniformiv(_handle, *err, &value);
    }

    return value;
}

unsigned int Shader::GetUInteger(const std::string& name, int* err)
{
    unsigned int value;

    *err = glGetUniformLocation(_handle, name.c_str());

    if (*err != -1)
    {
        glGetUniformuiv(_handle, *err, &value);
    }

    return value;
}


GLuint& Shader::GetProgram() {
	return _handle;
}

bool Shader::LinkProgram() {

	//Attach shaders to newly create program and then link everything
	for (std::map<GLenum, GLuint>::iterator it = _shaders.begin(); it != _shaders.end(); ++it)
	{
		glAttachShader(_handle, it->second);
	}


	glBindAttribLocation(_handle, 0, "Pos");
	glBindAttribLocation(_handle, 1, "Normal");
	glBindAttribLocation(_handle, 2, "TexCoord");

	glLinkProgram(_handle);

	glGetProgramiv(_handle, GL_LINK_STATUS, &_success);

	if (!_success) {
		glGetProgramInfoLog(_handle, ERR_LOG, NULL, _errLog);
		std::cout << "ERROR linking shader program ((-" << _handle << "-))\n\n" << _errLog << std::endl;
		return false;
	}

	return true;
}

void Shader::init_shader_map()
{
	_shaders.emplace(GL_VERTEX_SHADER, -1);
	_shaders.emplace(GL_FRAGMENT_SHADER, -1);
}

GLuint Shader::compile_shader(const std::string& shader_src, GLenum shader_type) {
	GLuint shader;
	//We have to convert to a type that OpenGL understands
	const GLchar* src[1];
	GLint src_length[1];

	src[0] = shader_src.c_str();
	src_length[0] = shader_src.length();

	//Create empty shader object of specified type
	shader = glCreateShader(shader_type);
	//Moves shader source code into shader object location
	glShaderSource(shader, 1, src, src_length);
	//Compiles source code into shader object
	glCompileShader(shader);

	//Check for compilation errors
	glGetShaderiv(shader, GL_COMPILE_STATUS, &_success);

	//If compilation had errors
	if (!_success) {
		glGetShaderInfoLog(shader, ERR_LOG, NULL, _errLog);
		std::cout << "\n SHADER COMPILATION ERROR ((- " << shader << " -))\n\n" << _errLog << std::endl;
	}

	return shader;
}

std::string Shader::load_shader(const std::string& filename){
	std::string line;
	std::ifstream shader_file(filename);
	std::string shader_src;

	if (shader_file.is_open()) {
		while (std::getline(shader_file, line)) {
			shader_src += line;
			shader_src.append("\n");
		}
		shader_file.close();
	}
	else {
		std::cout << "--Unable to load shader file--" << std::endl;
	}

	return shader_src;
}

Shader::~Shader()
{
	for (std::map<GLenum, GLuint>::iterator it = _shaders.begin(); it != _shaders.end(); ++it)
	{
		glDetachShader(_handle, it->second);
		glDeleteShader(it->second);
	}
}
