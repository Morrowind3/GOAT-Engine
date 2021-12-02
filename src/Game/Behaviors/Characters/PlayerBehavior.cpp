#include "PlayerBehavior.hpp"
#include "Scripts/Script_PlayerMovement.hpp"
#include "../../Keys.hpp"
#include "../Utils/Scripts/DamageScript.hpp"

PlayerBehavior::PlayerBehavior(Object_Player& player, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<Script_PlayerMovement>(player, true)));
    scripts.insert(std::make_pair(Keys::DAMAGE,std::make_shared<DamageScript>(player, true)));
}
