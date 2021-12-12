#ifndef GOAT_ENGINE_CLOUD_HPP
#define GOAT_ENGINE_CLOUD_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Cloud : public GameObject {
public:
    enum class Shape {
        BIG, WIDE, SMALL
    };
    Cloud(Shape shape, Transform transform, bool active);
};


#endif //GOAT_ENGINE_CLOUD_HPP
