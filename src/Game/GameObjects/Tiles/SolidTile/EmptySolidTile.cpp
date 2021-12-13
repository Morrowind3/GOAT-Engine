//
// Created by MDstu on 08/12/2021.
//

#include "EmptySolidTile.hpp"
#include "../../../Keys.hpp"

EmptySolidTile::EmptySolidTile(const std::string &sprite, Transform transform, bool active): Tile(sprite, transform, active) {
    tags.insert(std::make_pair(Keys::SOLID, true));
}