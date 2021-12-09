#include "SnowballBehavior.hpp"
#include "../../../Keys.hpp"
#include "SnowballScript.hpp"

// Expected behavior:
// - spawn some distance above original transform, to prevent early collisions
// - rolls down to left side
// - when collided with player or standing still, reset transform to original transform
// - deal damage and push player back when collided

SnowballBehavior::SnowballBehavior(Snowball& snowball, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::SNOWBALL, std::make_shared<SnowballScript>(snowball, true)));
}