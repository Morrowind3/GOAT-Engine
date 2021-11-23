#ifndef GOAT_ENGINE_PLAYERBEHAVIOR_HPP
#define GOAT_ENGINE_PLAYERBEHAVIOR_HPP

#include <memory>

#include "../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Scripts/PlayerMovementScript.hpp"

using namespace Engine;

class PlayerBehavior : public Behavior {
    public:
        PlayerBehavior(Player& player, bool active) : Behavior(active) {
            scripts.emplace_back(std::make_shared<PlayerMovementScript>(player, true));
        }
};


#endif //GOAT_ENGINE_PLAYERBEHAVIOR_HPP
