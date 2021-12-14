#ifndef GOAT_ENGINE_OBJECT_EMPTYSOLIDTILE_HPP
#define GOAT_ENGINE_OBJECT_EMPTYSOLIDTILE_HPP

#include "../Object_Tile.hpp"

using namespace Engine;

class Object_EmptySolidTile: public Object_Tile {
public: explicit Object_EmptySolidTile(const std::string &sprite, Transform transform,bool active);
};


#endif //GOAT_ENGINE_OBJECT_EMPTYSOLIDTILE_HPP
