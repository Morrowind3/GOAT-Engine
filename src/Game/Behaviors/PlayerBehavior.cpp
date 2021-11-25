#include "PlayerBehavior.hpp"
#include "Scripts/PlayerMovementScript.hpp"
#include "../Keys.hpp"

PlayerBehavior::PlayerBehavior(Player& player, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<PlayerMovementScript>(player, true)));
}
