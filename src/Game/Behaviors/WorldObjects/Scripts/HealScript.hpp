//
// Created by Morrowind3 on 29/11/2021.
//

#ifndef GOAT_ENGINE_HEALSCRIPT_HPP
#define GOAT_ENGINE_HEALSCRIPT_HPP


#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../GameObjects/WorldObjects/HealthPickup.hpp"

using namespace Engine;

class HealScript : public Script {
public:
    HealScript(HealthPickup& pickup, bool active);;
    void onTriggerEnter2D(GameObject &other) override;
    void onUpdate(double deltaTime) override;

private:
    double _originalY;
    double _animationtimer = 0;
    bool _movingUp = true;
    HealthPickup& _pickup;
};


#endif //GOAT_ENGINE_HEALSCRIPT_HPP
