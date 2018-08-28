
#include "IComponent.h"

#include <ctime>

ComponentID GenerateID()
{
    std::time_t currentTime = std::time(nullptr);
    std::string timeStampID = std::asctime(std::localtime(&currentTime));

    return timeStampID;
}