#version 330 core 

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out vec3 Position;
out vec3 Normal;
out vec2 TexCoord;

uniform mat4 mvp;

void main()
{
    gl_Position = mvp * vec4(position, 1.0);
    Position = position;
    Normal = normal;
    TexCoord = texCoord;
}