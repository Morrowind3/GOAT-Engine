#ifndef GOAT_ENGINE_VICTORYFLAGBEHAVIOR_HPP
#define GOAT_ENGINE_VICTORYFLAGBEHAVIOR_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../GameObjects/WorldObjects/VictoryFlag.hpp"

using namespace Engine;

class VictoryFlagBehavior : public Behavior {
    public: VictoryFlagBehavior(VictoryFlag& flag, const std::shared_ptr<Player>& player, bool active);

};


#endif //GOAT_ENGINE_VICTORYFLAGBEHAVIOR_HPP
