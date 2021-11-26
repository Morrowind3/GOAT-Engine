#ifndef GOAT_ENGINE_LIFEHEARTBEHAVIOR_HPP
#define GOAT_ENGINE_LIFEHEARTBEHAVIOR_HPP

#include "../../GameObjects/Meta/Hud/LifeHeart.hpp"

using namespace Engine;

class LifeHeartBehavior : public Behavior {
    public: LifeHeartBehavior(int filledAtHp, LifeHeart& lifeHeart, bool active);
};


#endif //GOAT_ENGINE_LIFEHEARTBEHAVIOR_HPP
