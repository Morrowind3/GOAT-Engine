#include "LifeHeart.hpp"
#include "../../../Keys.hpp"
#include "../../../Behaviors/Utils/LifeHeartBehavior.hpp"

LifeHeart::LifeHeart(int filledAtHp, Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::TRUE, Sprite{"Sprites/ui/rest/Health_full.png",true}));
    sprites.insert(std::make_pair(Keys::FALSE, Sprite{"Sprites/ui/rest/Health_empty.png",false}));
//    behaviors.insert(std::make_pair(Keys::HP, std::make_shared<LifeHeartBehavior>(filledAtHp, *this, true)));
}
