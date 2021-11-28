#ifndef GOAT_ENGINE_VICTORYBACKGROUND_HPP
#define GOAT_ENGINE_VICTORYBACKGROUND_HPP

#include "../../../../Engine/API/GameObjects/Transform.hpp"
#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class VictoryBackground : public GameObject {
    public: VictoryBackground(Transform transform, bool active);
};


#endif //GOAT_ENGINE_VICTORYBACKGROUND_HPP
