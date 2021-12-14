#include "Behavior_LoadScoreboardButton.hpp"
#include "../../../../Keys.hpp"
#include "../Script_LoadScoreboard.hpp"
#include "Script_OnClickSound.hpp"

Behavior_LoadScoreboardButton::Behavior_LoadScoreboardButton(unsigned short etappeNumber, Text& scoreboardHeader, AudioSource& clickSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::_, std::make_shared<Script_LoadScoreboard>(etappeNumber, scoreboardHeader, true)));
    scripts.insert(std::make_pair(Keys::AUDIO, std::make_shared<Script_OnClickSound>(clickSound, true)));
}

Behavior_LoadScoreboardButton::Behavior_LoadScoreboardButton(Text& scoreboardHeader, AudioSource& clickSound, bool active): Behavior(active) {
    scripts.insert(std::make_pair(Keys::_, std::make_shared<Script_LoadScoreboard>(scoreboardHeader, true)));
    scripts.insert(std::make_pair(Keys::AUDIO, std::make_shared<Script_OnClickSound>(clickSound, true)));
}
