#include "Tile.hpp"
#include "../../Keys.hpp"

Tile::Tile(const std::string& sprite, const std::shared_ptr<Behavior>& tileBehavior,
           Transform transform, bool active): GameObject(transform, active) {
    tags.insert(std::make_pair(Keys::TILE, true));
    sprites.insert(std::make_pair(Keys::SPRITE, Sprite{sprite, true}));
    behaviors.insert(std::make_pair(Keys::BEHAVIOR,tileBehavior));
};
