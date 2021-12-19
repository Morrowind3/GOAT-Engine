#include "Behavior_GameState.hpp"
#include "../../Keys.hpp"
#include "EtappeEndScene/Script_GameState.hpp"

Behavior_GameState::Behavior_GameState(std::shared_ptr<Object_Timer> timer, bool active)  : Behavior(active) {
    scripts.insert(std::make_pair(Keys::GAMESTATE,std::make_shared<Script_GameState>(timer,true)));
}

