
#ifndef ISYSTEM_H
#define ISYSTEM_H

#include "IComponent.h"

class ISystem 
{
public:
    ISystem();
    virtual ~ISystem();

    virtual void Update(float deltaTime, std::vector<IComponent*> components);

private:
    std::vector<ComponentID> _componentFilter;
};

#endif // ISYSTEM_H