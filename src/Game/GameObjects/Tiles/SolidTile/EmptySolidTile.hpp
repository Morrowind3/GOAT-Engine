//
// Created by MDstu on 08/12/2021.
//

#ifndef GOAT_ENGINE_EMPTYSOLIDTILE_HPP
#define GOAT_ENGINE_EMPTYSOLIDTILE_HPP

#include "../Tile.hpp"

using namespace Engine;

class EmptySolidTile: public Tile {
public: explicit EmptySolidTile(const std::string &sprite, Transform transform,bool active);
};


#endif //GOAT_ENGINE_EMPTYSOLIDTILE_HPP
