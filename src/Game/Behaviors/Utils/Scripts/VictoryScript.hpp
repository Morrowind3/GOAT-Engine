//
// Created by Morrowind3 on 26/11/2021.
//

#ifndef GOAT_ENGINE_VICTORYSCRIPT_HPP
#define GOAT_ENGINE_VICTORYSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/API/GameObjects/GameObject.hpp"

using namespace Engine;

class VictoryScript : public Script {
public:
    VictoryScript(bool active);
    void OnExternalEvent() override;

private:
};


#endif //GOAT_ENGINE_VICTORYSCRIPT_HPP
