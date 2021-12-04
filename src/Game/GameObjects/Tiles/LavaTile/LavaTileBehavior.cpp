#include "LavaTileBehavior.hpp"
#include "LavaTileScript.hpp"
#include "../../../Keys.hpp"

LavaTileBehavior::LavaTileBehavior(bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<LavaTileScript>(true)));
}