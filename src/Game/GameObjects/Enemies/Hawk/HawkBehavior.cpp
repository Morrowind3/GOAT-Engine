#include "HawkBehavior.hpp"
#include "../../../Keys.hpp"

// Expected behavior:
// - flies circles in the air
// - randomly dives to the ground (needs to have circled at least 1 time before can dive again)
// - when diving, go back up when collided with something
// - when collided with player, deal damage

HawkBehaviour::HawkBehaviour(Hawk& self, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::HAWK,std::make_shared<HawkScript>(self, true)));
}
