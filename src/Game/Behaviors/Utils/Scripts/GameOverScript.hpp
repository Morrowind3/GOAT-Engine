//
// Created by Morrowind3 on 26/11/2021.
//

#ifndef GOAT_ENGINE_GAMEOVERSCRIPT_HPP
#define GOAT_ENGINE_GAMEOVERSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"

using namespace Engine;

class GameOverScript : public Script{
public:
    explicit GameOverScript(bool active) : Script(active){};
    void OnStart() override;

};


#endif //GOAT_ENGINE_GAMEOVERSCRIPT_HPP
