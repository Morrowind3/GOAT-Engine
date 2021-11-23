#ifndef GOAT_ENGINE_SLABTILE_HPP
#define GOAT_ENGINE_SLABTILE_HPP

#include "./Tile.hpp"
#include <string>

using namespace Engine;

class SlabTile : public Tile {
public:
    explicit SlabTile(const std::string& sprite, Transform transform, bool active);
};


#endif //GOAT_ENGINE_SLABTILE_HPP
