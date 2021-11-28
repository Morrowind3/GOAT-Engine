#include "SlabTile.hpp"
#include "../../Behaviors/Tiles/SlabTileBehavior.hpp"

SlabTile::SlabTile(const std::string& sprite, Transform transform, bool active)
        : Tile(sprite, std::make_shared<SlabTileBehavior>(*this, active), "SLAB", transform, active) {
    rigidBody = {0.0f, 0.0f, BodyType::STATIC, true};
    collider = BoxCollider(21 * transform.scaleWidth,11 * transform.scaleHeight, true);
}