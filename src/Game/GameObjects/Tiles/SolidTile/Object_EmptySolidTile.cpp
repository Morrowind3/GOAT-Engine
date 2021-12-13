//
// Created by MDstu on 08/12/2021.
//

#include "Object_EmptySolidTile.hpp"
#include "../../../Keys.hpp"

Object_EmptySolidTile::Object_EmptySolidTile(const std::string &sprite, Transform transform, bool active): Object_Tile(sprite, transform, active) {
    tags.insert(std::make_pair(Keys::SOLID, true));
}