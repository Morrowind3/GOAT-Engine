#ifndef GOAT_ENGINE_PLAYERBEHAVIOR_HPP
#define GOAT_ENGINE_PLAYERBEHAVIOR_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Object_Player.hpp"

using namespace Engine;

class PlayerBehavior : public Behavior {
    public: PlayerBehavior(Object_Player& player, bool active);
};


#endif //GOAT_ENGINE_PLAYERBEHAVIOR_HPP
