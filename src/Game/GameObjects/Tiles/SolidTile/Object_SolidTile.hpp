#ifndef GOAT_ENGINE_OBJECT_SOLIDTILE_HPP
#define GOAT_ENGINE_OBJECT_SOLIDTILE_HPP

#include "../Object_Tile.hpp"

using namespace Engine;

class Object_SolidTile : public Object_Tile {
    public: explicit Object_SolidTile(const std::string& sprite, Transform transform, bool active);
};

#endif //GOAT_ENGINE_OBJECT_SOLIDTILE_HPP
