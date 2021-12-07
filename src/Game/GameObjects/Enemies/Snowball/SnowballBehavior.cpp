#include "SnowballBehavior.hpp"
#include "../../../Keys.hpp"
#include "SnowballScript.hpp"

// Expected behavior:
// - spawn 200px above original transfor
// - rolls down to left side
// - when collided with player or standing still, reset transform to original transform

SnowballBehavior::SnowballBehavior(Snowball& snowball, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::SNOWBALL, std::make_shared<SnowballScript>(snowball, true)));
}