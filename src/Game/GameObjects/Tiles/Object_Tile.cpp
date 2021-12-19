#include "Object_Tile.hpp"
#include "../../Keys.hpp"

Object_Tile::Object_Tile(const std::string& sprite, Transform transform, bool active) : GameObject(transform, active) {
    tags.insert(std::make_pair(Keys::TILE, true));
    sprites.insert(std::make_pair(Keys::SPRITE, Sprite{sprite, true}));
}

Object_Tile::Object_Tile(const std::string& sprite, const std::shared_ptr<Behavior>& tileBehavior,
           Transform transform, bool active) : GameObject(transform, active) {
    tags.insert(std::make_pair(Keys::TILE, true));
    sprites.insert(std::make_pair(Keys::SPRITE, Sprite{sprite, true}));
    behaviors.insert(std::make_pair(Keys::BEHAVIOR, tileBehavior));
};
