#include "Behavior_Player.hpp"
#include "Script_PlayerMovement.hpp"
#include "../../Keys.hpp"
#include "Script_Damage.hpp"

Behavior_Player::Behavior_Player(Object_Player& player, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<Script_PlayerMovement>(player, true)));
    scripts.insert(std::make_pair(Keys::DAMAGE,std::make_shared<Script_Damage>(player, true)));
}
