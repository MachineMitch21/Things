
#ifndef ICOMPONENT_H
#define ICOMPONENT_H

#include <cstddef>

#include "Entity.h"

typedef std::string ComponentID;

ComponentID GenerateID();

struct IComponent 
{
    EntityID            Parent;

    virtual ComponentID  GetID();
    virtual size_t       GetSize();
};

template<typename T>
struct Component    :   public IComponent
{
    static const ComponentID    ID;
    static const size_t         SIZE;

    static const ComponentID    GetID() override { return ID; };
    static const size_t         GetSize() override { return SIZE; };
};

template<typename T>
const ComponentID Component<T>::ID(GenerateID());

template<typename T>
const size_t Component<T>::SIZE(sizeof(T));

#endif // ICOMPONENT_H