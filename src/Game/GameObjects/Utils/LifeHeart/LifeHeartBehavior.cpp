#include "LifeHeartBehavior.hpp"
#include "../../../Keys.hpp"
#include "LifeHeartScript.hpp"

LifeHeartBehavior::LifeHeartBehavior(int filledAtHp, LifeHeart& lifeHeart, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::HP, std::make_shared<LifeHeartScript>(filledAtHp,lifeHeart,true)));
}
