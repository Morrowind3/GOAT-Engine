#include "SlabTile.hpp"
#include "../../Behaviors/Tiles/SlabTileBehavior.hpp"

SlabTile::SlabTile(const std::string& sprite, Transform transform, bool active)
        : Tile(sprite, std::make_shared<SlabTileBehavior>(*this, active), "SLAB", transform, active) { }