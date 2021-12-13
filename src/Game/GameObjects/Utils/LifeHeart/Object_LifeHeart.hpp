#ifndef GOAT_ENGINE_OBJECT_LIFEHEART_HPP
#define GOAT_ENGINE_OBJECT_LIFEHEART_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Object_LifeHeart : public GameObject {
    public: Object_LifeHeart(int filledAtHp, Transform transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_LIFEHEART_HPP
