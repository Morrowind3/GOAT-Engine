#ifndef GOAT_ENGINE_SLABTILEBEHAVIOR_HPP
#define GOAT_ENGINE_SLABTILEBEHAVIOR_HPP

#include "../../GameObjects/Tiles/SlabTile.hpp"

using namespace Engine;

class SlabTileBehavior : public Behavior {
    public: SlabTileBehavior(SlabTile& self, bool active);
};

#endif //GOAT_ENGINE_SLABTILEBEHAVIOR_HPP
