#include "VictorySceneBehavior.hpp"
#include "IncreaseEtappeCountScript.hpp"
#include "../../../Keys.hpp"

VictorySceneBehavior::VictorySceneBehavior(bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::ETAPPE_SELECT,std::make_shared<IncreaseEtappeCountScript>(true)));
}
