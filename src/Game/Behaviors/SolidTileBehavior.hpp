#ifndef GOAT_ENGINE_SOLIDTILEBEHAVIOR_HPP
#define GOAT_ENGINE_SOLIDTILEBEHAVIOR_HPP

#include <memory>

#include "../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "Scripts/PlayerMovementScript.hpp"

using namespace Engine;

class SolidTileBehavior : public Behavior {
public:
    SolidTileBehavior(SolidTile& self, bool active) : Behavior(active) {
    }
};


#endif //GOAT_ENGINE_SOLIDTILEBEHAVIOR_HPP
