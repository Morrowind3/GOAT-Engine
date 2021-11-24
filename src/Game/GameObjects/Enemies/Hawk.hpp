//
// Created by Stijn van Loon on 24-11-2021.
//

#ifndef GOAT_ENGINE_HAWK_HPP
#define GOAT_ENGINE_HAWK_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

namespace HAWK {
    const std::string MOVE1 = "Move1";
    const std::string MOVE2 = "Move2";
    const std::string BEHAVIOR = "Behavior";
}

class Hawk : public GameObject {
public:
    Hawk(Transform transform, bool active);
};



#endif //GOAT_ENGINE_HAWK_HPP
