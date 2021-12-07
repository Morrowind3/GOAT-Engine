#ifndef GOAT_ENGINE_WALLTILE_HPP
#define GOAT_ENGINE_WALLTILE_HPP

#include "../Tile.hpp"

using namespace Engine;

class WallTile : public Tile {
public: explicit WallTile(const std::string& sprite, Transform transform, bool active);
};


#endif //GOAT_ENGINE_WALLTILE_HPP
