//
// Created by MDstu on 15/12/2021.
//

#include "Object_IceTile.hpp"
#include "../../../Keys.hpp"

Object_IceTile::Object_IceTile(const std::string &sprite, Transform transform, bool active) : Object_Tile(sprite,transform,active) {
    tags.insert(std::make_pair(Keys::SOLID, true));
    rigidBody = {0.0f, 0.0f, BodyType::STATIC, true};
    collider = BoxCollider(21 * transform.scaleWidth,21 * transform.scaleHeight, 0.02f ,0,false, true);
}