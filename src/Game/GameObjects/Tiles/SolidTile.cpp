//
// Created by Stijn van Loon on 22-11-2021.
//

#include "SolidTile.hpp"

#include <utility>

SolidTile::SolidTile(std::string sprite, Transform transform, bool active) : GameObject(transform, active) {
    sprites.insert(std::make_pair(SOLIDTILE::SPRITE, Sprite{std::move(sprite),true}));
}