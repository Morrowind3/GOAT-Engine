#include "GoatBehavior.hpp"
#include "../../../Keys.hpp"
#include "GoatScript.hpp"

// Expected behavior:
// - walks back and forth on the same tile height (so will never go down or up)
// - when walking to the left, go into angry mode (walk faster + different sprites)
// - on player collision, damage & push player, switch direction goat

GoatBehavior::GoatBehavior(Goat& goat, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::GOAT, std::make_shared<GoatScript>(goat, true)));
}
