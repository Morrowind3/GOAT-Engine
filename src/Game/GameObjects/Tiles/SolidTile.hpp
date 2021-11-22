//
// Created by Stijn van Loon on 22-11-2021.
//

#ifndef GOAT_ENGINE_SOLIDTILE_HPP
#define GOAT_ENGINE_SOLIDTILE_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include <string>

using namespace Engine;

namespace SOLIDTILE {
    const std::string SPRITE = "Sprite";
}

class SolidTile : public GameObject {
public:
    explicit SolidTile(std::string sprite, Transform transform, bool active);
};


#endif //GOAT_ENGINE_SOLIDTILE_HPP
