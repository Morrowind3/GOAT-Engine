//
// Created by MDstu on 15/12/2021.
//

#ifndef GOAT_ENGINE_OBJECT_ICETILE_HPP
#define GOAT_ENGINE_OBJECT_ICETILE_HPP

#include "../Object_Tile.hpp"

using namespace Engine;

class Object_IceTile : public Object_Tile {
public: explicit Object_IceTile(const std::string &sprite, Transform transform, bool active);
};


#endif //GOAT_ENGINE_OBJECT_ICETILE_HPP
