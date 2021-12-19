#ifndef GOAT_ENGINE_BEHAVIOR_LIFEHEART_HPP
#define GOAT_ENGINE_BEHAVIOR_LIFEHEART_HPP

#include "Object_LifeHeart.hpp"

using namespace Engine;

class Behavior_LifeHeart : public Behavior {
    public: Behavior_LifeHeart(int filledAtHp, Object_LifeHeart& lifeHeart, bool active);
};

#endif //GOAT_ENGINE_BEHAVIOR_LIFEHEART_HPP
