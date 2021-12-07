#ifndef GOAT_ENGINE_SNOWBALL_HPP
#define GOAT_ENGINE_SNOWBALL_HPP


#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Snowball : public GameObject {
public:
    Snowball(Transform transform, bool active);
};

#endif //GOAT_ENGINE_SNOWBALL_HPP
