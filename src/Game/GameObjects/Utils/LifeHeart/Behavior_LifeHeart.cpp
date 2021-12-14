#include "Behavior_LifeHeart.hpp"
#include "../../../Keys.hpp"
#include "Script_LifeHeart.hpp"

Behavior_LifeHeart::Behavior_LifeHeart(int filledAtHp, Object_LifeHeart& lifeHeart, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::HP, std::make_shared<Script_LifeHeart>(filledAtHp,lifeHeart,true)));
}
