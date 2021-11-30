#include "../../Keys.hpp"
#include "VictoryFlagBehavior.hpp"
#include "Scripts/FlagScript.hpp"

VictoryFlagBehavior::VictoryFlagBehavior(VictoryFlag& flag,bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<FlagScript>(true, flag )));

}
