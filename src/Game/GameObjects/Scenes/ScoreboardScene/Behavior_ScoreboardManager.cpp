#include "Behavior_ScoreboardManager.hpp"
#include "../../../Keys.hpp"
#include "Script_LoadScoreboard.hpp"

Behavior_ScoreboardManager::Behavior_ScoreboardManager(Text& scoreboardHeader, bool active): Behavior(active) {
    auto& script = scripts.insert(std::make_pair(Keys::_, std::make_shared<Script_LoadScoreboard>(scoreboardHeader, true))).first->second;
    script->onExternalEvent(); // Scoreboard manager will set the scoreboards initial state to show the highscore of all etappes
}
