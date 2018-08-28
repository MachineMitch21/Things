
#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include <map>

#include "Entity.h"
#include "ISystem.h"
#include "IComponent.h"

class World 
{
public:
    World();
    ~World();

    EntityID CreateEntity(std::vector<IComponent*> components);
    void RemoveEntity(EntityID entity);

    void AddComponent(EntityID, IComponent* component);
    void RemoveComponent(EntityID, IComponent* component);

    void Update(float deltaTime);

    void AddSystem(ISystem* nSystem);
    void RemoveSystem(ISystem* nSystem);

private:
    std::vector<ISystem*>                           _systems;
    std::map<EntityID, std::vector<ComponentID>>    _entities; 
    std::map<std::vector<IComponent*>>              _components;
};

#endif // WORLD_H