#include "LavaTile.hpp"
#include "../../../Keys.hpp"
#include "LavaTileBehavior.hpp"

LavaTile::LavaTile(Transform transform, bool active)
        : Tile("Sprites/utils/lakes/lake_lava.png", std::make_shared<LavaTileBehavior>(active), transform, active) {
    tags.insert(std::make_pair(Keys::SLAB, true));
    rigidBody = {0.0f, 0.0f, BodyType::STATIC, true};
    collider = BoxCollider(21 * transform.scaleWidth, 7 * transform.scaleHeight,0.07f, true,  true);
}