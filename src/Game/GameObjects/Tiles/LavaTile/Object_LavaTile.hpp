#ifndef GOAT_ENGINE_OBJECT_LAVATILE_HPP
#define GOAT_ENGINE_OBJECT_LAVATILE_HPP


#include "../Object_Tile.hpp"

using namespace Engine;

class Object_LavaTile : public Object_Tile {
public:
    explicit Object_LavaTile(Transform transform, bool active);
};

#endif //GOAT_ENGINE_OBJECT_LAVATILE_HPP
