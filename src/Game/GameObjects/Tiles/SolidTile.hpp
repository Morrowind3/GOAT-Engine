#ifndef GOAT_ENGINE_SOLIDTILE_HPP
#define GOAT_ENGINE_SOLIDTILE_HPP

#include "./Tile.hpp"

using namespace Engine;

class SolidTile : public Tile {
    public: explicit SolidTile(const std::string& sprite, Transform transform, bool active);
};

#endif //GOAT_ENGINE_SOLIDTILE_HPP
