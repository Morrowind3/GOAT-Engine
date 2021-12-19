#ifndef GOAT_ENGINE_OBJECT_WALLTILE_HPP
#define GOAT_ENGINE_OBJECT_WALLTILE_HPP

#include "../Object_Tile.hpp"

using namespace Engine;

class Object_WallTile : public Object_Tile {
public: explicit Object_WallTile(const std::string& sprite, Transform transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_WALLTILE_HPP
