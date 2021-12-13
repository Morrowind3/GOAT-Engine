#include "Object_LifeHeart.hpp"
#include "../../../Keys.hpp"
#include "Behavior_LifeHeart.hpp"

Object_LifeHeart::Object_LifeHeart(int filledAtHp, Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(Keys::TRUE, Sprite{"Sprites/ui/rest/Health_full.png",true}));
    sprites.insert(std::make_pair(Keys::FALSE, Sprite{"Sprites/ui/rest/Health_empty.png",false}));
    behaviors.insert(std::make_pair(Keys::HP, std::make_shared<Behavior_LifeHeart>(filledAtHp, *this, true)));
}
