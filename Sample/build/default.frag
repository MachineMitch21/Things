#version 330 core 

in vec3 Position;
in vec3 Normal;
in vec2 TexCoord;

out vec4 FragColor;

uniform mat4 modelMatrix;
uniform mat3 normalMatrix;

uniform float attenCoef;
uniform float attenLinear;
uniform float attenSquare;

uniform vec3 lightPos;
uniform vec4 lightColor;
uniform float lightIntensity;

float diffuse(vec3 worldPos)
{
    vec3 lightDir = (lightPos - worldPos);

    vec3 worldNormal = normalize(normalMatrix * Normal);

    float d = max(dot(worldNormal, lightDir), 0.0);

    return d;     
}

void main()
{
    vec3 worldPos = (modelMatrix * vec4(Position, 1.0)).xyz;

    float d = diffuse(worldPos);

    float dist = distance(worldPos, lightPos);

    float atten = 1.0 / (attenCoef + (attenLinear * dist + attenSquare * pow(dist, 2)));

    float lightContribution = (((lightColor.x * lightIntensity) + (lightColor.y * lightIntensity) + (lightColor.z * lightIntensity)) / 3);

    FragColor = ((vec4(0.8, 0.8, 0.8, 1.0) * d * atten) + (lightColor * d * atten)) * lightContribution;
}