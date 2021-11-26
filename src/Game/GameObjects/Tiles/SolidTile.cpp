#include "SolidTile.hpp"
#include "../../Behaviors/Tiles/SolidTileBehavior.hpp"

SolidTile::SolidTile(const std::string& sprite, Transform transform, bool active)
        : Tile(sprite, std::make_shared<SolidTileBehavior>(*this, active), "SOLID", transform, active) {
}