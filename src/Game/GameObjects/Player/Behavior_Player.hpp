#ifndef GOAT_ENGINE_BEHAVIOR_PLAYER_HPP
#define GOAT_ENGINE_BEHAVIOR_PLAYER_HPP

#include "../../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Object_Player.hpp"

using namespace Engine;

class Behavior_Player : public Behavior {
    public: Behavior_Player(Object_Player& player, bool active);
};


#endif //GOAT_ENGINE_BEHAVIOR_PLAYER_HPP
