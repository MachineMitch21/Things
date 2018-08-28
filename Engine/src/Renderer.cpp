
#include "Renderer.h"

#include <iostream>

MeshComponent::MeshComponent(std::vector<Vertex>& vertices, std::vector<unsigned int>& indices) : Vertices(vertices), Indices(indices) { }
MeshComponent::~MeshComponent() { } 

Renderer::Renderer(class ECS::World* world)
{
    _world = world;
    GLenum err = glewInit();

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_STENCIL_TEST);

    glDepthFunc(GL_LESS);

    world->subscribe<ECS::Events::OnComponentAssigned<MeshComponent>>(this);
    world->subscribe<OnMeshChanged>(this);
}

Renderer::~Renderer()
{

}

void render()
{

}

void Renderer::receive(class ECS::World* world, const OnMeshChanged& event) 
{
    std::cout << "A Mesh was changed" << std::endl;
}

void Renderer::receive(class ECS::World* world, const ECS::Events::OnComponentAssigned<MeshComponent>& event) 
{
    ECS::Entity* entity = event.entity;
    const MeshComponent meshComponent = event.component.get();

    ECS::ComponentHandle<RenderComponent> renderComponent;

    if (!entity->has<RenderComponent>())
    {
        Shader* shader("default.vert", "default.frag");
        renderComponent = entity->assign<RenderComponent>(shader);
    }
}

void Renderer::receive(class ECS::World* world, const ECS::Events::OnComponentAssigned<RenderComponent>& event)
{
    RenderComponent renderComponent = event.component.get();

    glGenVertexArrays(1, &renderComponent->VAO);
    glGenBuffers(1, &renderComponent->VBO);
    glGenBuffers(1, &renderComponent->EBO);
}