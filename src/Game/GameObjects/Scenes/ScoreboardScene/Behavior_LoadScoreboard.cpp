#include "Behavior_LoadScoreboard.hpp"
#include "../../../Keys.hpp"
#include "Script_LoadScoreboard.hpp"

Behavior_LoadScoreboard::Behavior_LoadScoreboard(unsigned short etappeNumber, Text& scoreboardHeader, bool active): Behavior(active) {
    auto& script = scripts.insert(std::make_pair(Keys::_, std::make_shared<Script_LoadScoreboard>(etappeNumber, scoreboardHeader, true))).first->second;
}

Behavior_LoadScoreboard::Behavior_LoadScoreboard(Text& scoreboardHeader, bool active): Behavior(active) {
    auto& script = scripts.insert(std::make_pair(Keys::_, std::make_shared<Script_LoadScoreboard>(scoreboardHeader, true))).first->second;
}
