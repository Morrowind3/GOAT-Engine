#include "Behavior_Goat.hpp"
#include "../../../Keys.hpp"
#include "Script_Goat.hpp"

// Expected behavior:
// - walks back and forth on the same tile height (so will never go down or up)
// - when walking to the left, go into angry mode (walk faster + different sprites)
// - on player collision, damage & push player, switch direction goat

Behavior_Goat::Behavior_Goat(Object_Goat& goat, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::GOAT, std::make_shared<Script_Goat>(goat, true)));
}
