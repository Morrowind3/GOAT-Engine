#include "SlabTile.hpp"
#include "../../Behaviors/SlabTileBehavior.hpp"

SlabTile::SlabTile(std::string sprite, Transform transform, bool active)
        : Tile(sprite, *new SlabTileBehavior{*this, active}, "SLAB", transform, active) { }