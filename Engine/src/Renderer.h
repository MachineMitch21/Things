
#ifndef RENDERER_H
#define RENDERER_H

#include "vendor/ECS/ECS.h"

#include "Shader.h"

#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>

struct Vertex 
{
    Vertex() { }
    ~Vertex() { }

    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoord;
};

struct MeshComponent
{
    MeshComponent(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices);
    ~MeshComponent();
    
    std::vector<Vertex> Vertices;
    std::vector<unsigned int> Indices;
};

struct OnMeshChanged 
{
    ECS::Entity* entity;
    ECS::ComponentHandle<MeshComponent>  mesh;
};

struct RenderComponent 
{
    RenderComponent(Shader* shader) : SHADER(shader) { }
    ~RenderComponent() {}

    GLuint VAO, VBO, EBO;

    Shader* SHADER;
};

class Renderer : 
        public ECS::EventSubscriber<ECS::Events::OnComponentAssigned<MeshComponent>>,
        public ECS::EventSubscriber<ECS::Events::OnComponentAssigned<RenderComponent>>,
        public ECS::EventSubscriber<OnMeshChanged>
{
public:
    Renderer(class ECS::World* world);
    ~Renderer();

    virtual void receive(class ECS::World* world, const ECS::Events::OnComponentAssigned<MeshComponent>& event) override;
    virtual void receive(class ECS::World* world, const ECS::Events::OnComponentAssigned<RenderComponent>& event) override;
    virtual void receive(class ECS::World* world, const OnMeshChanged& event) override;

    void render();

private:
    ECS::World* _world;
};

#endif // RENDERER_H