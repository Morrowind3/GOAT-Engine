//
// Created by Morrowind3 on 26/11/2021.
//

#ifndef GOAT_ENGINE_FLAGSCRIPT_HPP
#define GOAT_ENGINE_FLAGSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../GameObjects/WorldObjects/VictoryFlag.hpp"
#include "../../../GameObjects/Characters/Player.hpp"

using namespace Engine;

class FlagScript : public Script {
public:
//    FlagScript(bool active, VictoryFlag& flag, Player& player);
    FlagScript(bool active, VictoryFlag& flag); //temp

    void OnUpdate(double deltaTime) override;
private:
    bool PlayerEntered();
    void AnimateFlag();
    VictoryFlag& _flag;
    double animationTimer = 0;
//    Player& _player;
};


#endif //GOAT_ENGINE_FLAGSCRIPT_HPP
