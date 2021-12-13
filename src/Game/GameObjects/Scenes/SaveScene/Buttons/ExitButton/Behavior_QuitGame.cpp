#include "Behavior_QuitGame.hpp"
#include "Script_QuitGame.hpp"
#include "../../../../../Keys.hpp"

Behavior_QuitGame::Behavior_QuitGame(bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<Script_QuitGame>(true)));
}
