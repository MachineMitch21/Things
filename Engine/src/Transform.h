
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <glm/glm.hpp>
#include <glm/mat4x4.hpp> 
#include <glm/gtc/quaternion.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

struct Transform 
{
    Transform(glm::vec3 pos, glm::vec3 scale, glm::vec3 rotEuler)
        :   Position(pos),
            Scale(scale)
    {
        Rotation = glm::quat(   glm::vec3
                                ( 
                                    glm::radians(rotEuler.x),
                                    glm::radians(rotEuler.y),
                                    glm::radians(rotEuler.z)
                                )
                            );
    }

    Transform(glm::vec3 pos, glm::vec3 scale, glm::quat rot) : Position(pos), Scale(scale), Rotation(rot) {}
    Transform() { }
    ~Transform() { }

    glm::vec3 Position;
    glm::vec3 Scale;
    glm::quat Rotation;
};

struct TransformMatrix 
{
    TransformMatrix(glm::mat4 matrix)   :   Model(matrix) { }
    ~TransformMatrix() {}

    glm::mat4 Model;
};

namespace TransformHelper
{
    const glm::mat4 GetTransformationMatrix(const Transform& t);
}


#endif // TRANSFORM_H