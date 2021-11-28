//
// Created by Morrowind3 on 26/11/2021.
//
#include "../../Keys.hpp"
#include "VictoryFlagBehavior.hpp"
#include "Scripts/FlagScript.hpp"

VictoryFlagBehavior::VictoryFlagBehavior(VictoryFlag& flag, const std::shared_ptr<Player>& player, bool active) : Behavior(active) {
    scripts.insert(std::make_pair(Keys::BEHAVIOR,std::make_shared<FlagScript>(true, flag, player )));
}
