#include "Behavior_VictoryScreen.hpp"
#include "Script_IncreaseEtappeCount.hpp"
#include "../../../Keys.hpp"

Behavior_VictoryScreen::Behavior_VictoryScreen(bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::ETAPPE_SELECT,std::make_shared<Script_IncreaseEtappeCount>(true)));
}
