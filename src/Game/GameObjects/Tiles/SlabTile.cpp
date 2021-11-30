#include "SlabTile.hpp"
#include "../../Keys.hpp"

SlabTile::SlabTile(const std::string& sprite, Transform transform, bool active)
        : Tile(sprite, transform, active) {
    tags.insert(std::make_pair(Keys::SLAB, true));
    rigidBody = {0.0f, 0.0f, BodyType::STATIC, true};
    collider = BoxCollider(21 * transform.scaleWidth, 7 * transform.scaleHeight, true);
}