#include "Object_WallTile.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Collision/BoxCollider.hpp"
#include "../../../Keys.hpp"

Object_WallTile::Object_WallTile(const std::string& sprite, Transform transform, bool active)
        : Object_Tile(sprite, transform, active) {
    tags.insert(std::make_pair(Keys::WALL, true));
    rigidBody = {0.0f, 0.0f, BodyType::STATIC, true};
    collider = BoxCollider(21 * transform.scaleWidth,21 * transform.scaleHeight, 0.07f, 0,false, true);
}