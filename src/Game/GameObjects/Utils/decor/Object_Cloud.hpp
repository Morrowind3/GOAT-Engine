#ifndef GOAT_ENGINE_OBJECT_CLOUD_HPP
#define GOAT_ENGINE_OBJECT_CLOUD_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_Cloud : public GameObject {
public:
    enum class CloudShape {
        BIG, WIDE, SMALL
    };
    Object_Cloud(CloudShape shape, Transform transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_CLOUD_HPP
