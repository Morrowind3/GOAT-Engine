#include "SolidTile.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Collision/BoxCollider.hpp"
#include "../../Keys.hpp"

SolidTile::SolidTile(const std::string& sprite, Transform transform, bool active)
        : Tile(sprite, transform, active) {
    tags.insert(std::make_pair(Keys::SOLID, true));
    rigidBody = {0.0f, 0.0f, BodyType::STATIC, true};
    collider = BoxCollider(21 * transform.scaleWidth,21 * transform.scaleHeight, false, true);
}