#include "Behavior_Snowball.hpp"
#include "../../../Keys.hpp"
#include "Script_Snowball.hpp"

// Expected behavior:
// - spawn some distance above original transform, to prevent early collisions
// - rolls down to left side
// - when collided with player or standing still, reset transform to original transform
// - deal damage and push player back when collided

Behavior_Snowball::Behavior_Snowball(Object_Snowball& snowball, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::SNOWBALL, std::make_shared<Script_Snowball>(snowball, true)));
}