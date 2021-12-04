#ifndef GOAT_ENGINE_LAVATILE_HPP
#define GOAT_ENGINE_LAVATILE_HPP


#include "./Tile.hpp"

using namespace Engine;

class LavaTile : public Tile {
public:
    explicit LavaTile(Transform transform, bool active);
};

#endif //GOAT_ENGINE_LAVATILE_HPP
