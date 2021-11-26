#ifndef GOAT_ENGINE_PLAYERBEHAVIOR_HPP
#define GOAT_ENGINE_PLAYERBEHAVIOR_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "../../GameObjects/Characters/Player.hpp"

using namespace Engine;

class PlayerBehavior : public Behavior {
    public: PlayerBehavior(Player& player, bool active);
};


#endif //GOAT_ENGINE_PLAYERBEHAVIOR_HPP
