#ifndef GOAT_ENGINE_PLAYERBEHAVIOR_HPP
#define GOAT_ENGINE_PLAYERBEHAVIOR_HPP

#include <memory>

#include "../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Scripts/PlayerMovementScript.hpp"

using namespace Engine;

class PlayerBehavior : public Behavior {
    public:
        PlayerBehavior(Player& player, bool active) : Behavior(active) {
            _playerMovementScript = std::make_unique<PlayerMovementScript>(player,true);
            scripts.emplace_back(_playerMovementScript.get());
        }
    private:
        std::unique_ptr<PlayerMovementScript> _playerMovementScript;
};


#endif //GOAT_ENGINE_PLAYERBEHAVIOR_HPP
