
#include "World.h"

World::World()
{

}

World::~World()
{

}

EntityID World::CreateEntity(std::vector<IComponent*> components)
{
    EntityID newEntityID = _entities.size();

    unsigned int i;
    for (i = 0; i < components.size(); i++)
    {
        ComponentID compID = components[i]->GetID();

        components[i]->Parent = newEntityID;
        _entities[newEntityID].push_back(compID);
        _components[compID].push_back(components[i]);
    }
}

void World::RemoveEntity(EntityID entity)
{
    
}

void World::AddComponent(EntityID entity, IComponent* component)
{

}

void World::RemoveComponent(EntityID entity, IComponent* component)
{

}