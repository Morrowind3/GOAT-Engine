//
// Created by Stijn van Loon on 24-11-2021.
//

#ifndef GOAT_ENGINE_HAWKSCRIPT_HPP
#define GOAT_ENGINE_HAWKSCRIPT_HPP

#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../GameObjects/Enemies/Hawk.hpp"
#include <ctime>

using namespace Engine;

enum Direction {
    LEFT,
    RIGHT
};

class HawkScript : public Script {
public:
    HawkScript(Hawk& self, bool active);
    void OnUpdate(double deltaTime);
private:
    Hawk& _self;
    Point _startingPos;
    Direction _direction = RIGHT;
    int _updateCounter{0};
//    std::time_t _lastMoveTime = std::time(0);

};


#endif //GOAT_ENGINE_HAWKSCRIPT_HPP
