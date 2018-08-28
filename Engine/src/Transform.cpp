
#include "Transform.h"

namespace TransformHelper
{
    const glm::mat4 GetTransformationMatrix(const Transform& t)
    {
        glm::mat4 model = glm::mat4(1.0f);
        
        glm::mat4 translation   = glm::translate(model, t.Position);
        glm::mat4 rotation      = glm::mat4_cast(t.Rotation);
        glm::mat4 scale         = glm::scale(model, t.Scale);

        model = translation * rotation * scale;

        return model;
    }
}