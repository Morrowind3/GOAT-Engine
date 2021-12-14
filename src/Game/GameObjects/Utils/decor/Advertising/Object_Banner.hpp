#ifndef GOAT_ENGINE_OBJECT_BANNER_HPP
#define GOAT_ENGINE_OBJECT_BANNER_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_Banner : public GameObject {
public:
    Object_Banner(Transform& tranform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_BANNER_HPP
