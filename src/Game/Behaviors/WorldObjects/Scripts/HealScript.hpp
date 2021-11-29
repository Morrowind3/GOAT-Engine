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
    HealScript(HealthPickup& pickup, bool active) : Script(active), _pickup(pickup){};
    void onTriggerEnter2D(GameObject &other) override;
private:
    HealthPickup& _pickup;
};


#endif //GOAT_ENGINE_HEALSCRIPT_HPP
