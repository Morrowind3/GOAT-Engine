//
// Created by Morrowind3 on 01/12/2021.
//

#ifndef GOAT_ENGINE_TIMER_HPP
#define GOAT_ENGINE_TIMER_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class Timer : public GameObject {
public:
    Timer(Transform transform, bool active);;
};


#endif //GOAT_ENGINE_TIMER_HPP
