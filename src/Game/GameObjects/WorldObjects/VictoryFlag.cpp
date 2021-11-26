//
// Created by Morrowind3 on 26/11/2021.
//

#include "VictoryFlag.hpp"
#include "../../Keys.hpp"
#include "../../Behaviors/WorldObjects/VictoryFlagBehavior.hpp"


VictoryFlag::VictoryFlag(Transform transform, bool active) : GameObject(transform, active) {
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<VictoryFlagBehavior>(*this, true)));
    sprites.insert(std::make_pair("Default", Sprite{"Sprites/utils/flag/Flag.png",true}));
    sprites.insert(std::make_pair("Wave", Sprite{"Sprites/utils/flag/Flag_wave.png",false}));

}