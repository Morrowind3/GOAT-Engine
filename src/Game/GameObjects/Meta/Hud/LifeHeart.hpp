#ifndef GOAT_ENGINE_LIFEHEART_HPP
#define GOAT_ENGINE_LIFEHEART_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class LifeHeart : public GameObject {
    public: LifeHeart(int filledAtHp, Transform transform, bool active);
};


#endif //GOAT_ENGINE_LIFEHEART_HPP
