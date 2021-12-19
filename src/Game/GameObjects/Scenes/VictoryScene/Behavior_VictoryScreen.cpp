#include "Behavior_VictoryScreen.hpp"
#include "Script_IncreaseEtappeCount.hpp"
#include "../../../Keys.hpp"
#include "Script_SaveHighScore.hpp"

Behavior_VictoryScreen::Behavior_VictoryScreen(Text& trashText, Text& timeText, Text& scoreText, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::ETAPPE_SELECT,std::make_shared<Script_IncreaseEtappeCount>(true)));
    scripts.insert(std::make_pair(Keys::SAVE_SCORE, std::make_shared<Script_SaveHighScore>(trashText,timeText,scoreText,true)));
}
