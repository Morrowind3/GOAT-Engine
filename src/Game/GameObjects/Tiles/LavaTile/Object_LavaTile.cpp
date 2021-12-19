#include "Object_LavaTile.hpp"
#include "../../../Keys.hpp"
#include "Behavior_LavaTile.hpp"

Object_LavaTile::Object_LavaTile(Transform transform, bool active)
        : Object_Tile("Sprites/utils/lakes/lake_lava.png", std::make_shared<Behavior_LavaTile>(active), transform, active) {
    tags.insert(std::make_pair(Keys::SLAB, true));
    rigidBody = {0.0f, 0.0f, BodyType::STATIC, true};
    collider = BoxCollider(21 * transform.scaleWidth, 7 * transform.scaleHeight,0.07f,0, 0,0,true,  true);
}