#ifndef GOAT_ENGINE_SLABTILEBEHAVIOR_HPP
#define GOAT_ENGINE_SLABTILEBEHAVIOR_HPP

#include <memory>
#include "../../Engine/API/GameObjects/GameComponents/Script/Behavior.hpp"
#include "./Scripts/SlabTileScript.hpp"

using namespace Engine;

class SlabTileBehavior : public Behavior {
public:
    SlabTileBehavior(SlabTile& self, bool active) : Behavior(active) {
        scripts.emplace_back(std::make_shared<SlabTileScript>(self, true));
    }
};

#endif //GOAT_ENGINE_SLABTILEBEHAVIOR_HPP
