#include "SolidTile.hpp"
#include "../../Behaviors/SolidTileBehavior.hpp"

SolidTile::SolidTile(std::string sprite, Transform transform, bool active)
        : Tile(sprite, *new SolidTileBehavior{*this, active}, "SOLID", transform, active) {
}