#ifndef GOAT_ENGINE_SOLIDTILE_HPP
#define GOAT_ENGINE_SOLIDTILE_HPP

#include "./Tile.hpp"
#include <string>

using namespace Engine;

class SolidTile : public Tile {
public:
    explicit SolidTile(std::string sprite, Transform transform, bool active);
};


#endif //GOAT_ENGINE_SOLIDTILE_HPP
