#ifndef GOAT_ENGINE_OBJECT_SLABTILE_HPP
#define GOAT_ENGINE_OBJECT_SLABTILE_HPP

#include "../Object_Tile.hpp"

using namespace Engine;

class Object_SlabTile : public Object_Tile {
    public: explicit Object_SlabTile(const std::string& sprite, Transform transform, bool active);
};

#endif //GOAT_ENGINE_OBJECT_SLABTILE_HPP
