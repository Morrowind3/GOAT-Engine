//
// Created by Morrowind3 on 26/11/2021.
//
#include "../../../Engine/API/GameObjects/GameObject.hpp"

#ifndef GOAT_ENGINE_VICTORYFLAG_HPP
#define GOAT_ENGINE_VICTORYFLAG_HPP

using namespace Engine;

class VictoryFlag : public GameObject {
    public: VictoryFlag(Transform transform, bool active);
};


#endif //GOAT_ENGINE_VICTORYFLAG_HPP
