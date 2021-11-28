#include "VictoryFlag.hpp"
#include "../../Keys.hpp"
#include "../../Behaviors/WorldObjects/VictoryFlagBehavior.hpp"


VictoryFlag::VictoryFlag(Transform transform, const std::shared_ptr<Player>& player, bool active) : GameObject(transform, active) {
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, std::make_shared<VictoryFlagBehavior>(*this, player, true)));
    sprites.insert(std::make_pair("Default", Sprite{"Sprites/utils/flag/Flag.png",true}));
    sprites.insert(std::make_pair("Wave", Sprite{"Sprites/utils/flag/Flag_wave.png",false}));

}