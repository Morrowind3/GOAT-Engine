#include "PlayerBehavior.hpp"
#include "PlayerMovementScript.hpp"
#include "../../Keys.hpp"
#include "DamageScript.hpp"

PlayerBehavior::PlayerBehavior(Player& player, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<PlayerMovementScript>(player, true)));
    scripts.insert(std::make_pair(Keys::DAMAGE,std::make_shared<DamageScript>(player, true)));
}
