#include "../../../Keys.hpp"
#include "Behavior_VictoryFlag.hpp"
#include "Script_VictoryFlag.hpp"

Behavior_VictoryFlag::Behavior_VictoryFlag(Object_VictoryFlag& flag,bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<Script_VictoryFlag>(true, flag )));

}
