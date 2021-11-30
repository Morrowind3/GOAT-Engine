#include "VictoryScreenBehavior.hpp"
#include "Scripts/IncreaseEtappeCountScript.hpp"
#include "../../Keys.hpp"

VictoryScreenBehavior::VictoryScreenBehavior(bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::ETAPPE_SELECT,std::make_shared<IncreaseEtappeCountScript>(true)));
}
