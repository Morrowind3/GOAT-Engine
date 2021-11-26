//
// Created by Morrowind3 on 26/11/2021.
//

#include "FlagScript.hpp"
#include "../../Utils/Scripts/VictoryScript.hpp"
#include <iostream>

//FlagScript::FlagScript(bool active, VictoryFlag& flag, Player& player) : Script(active), _flag(flag), _player(player) {
//}
FlagScript::FlagScript(bool active, VictoryFlag& flag) : Script(active), _flag(flag) {
}

void FlagScript::OnUpdate(double deltaTime) {
    if(PlayerEntered()){
//        VictoryScript victoryScript;
//        victoryScript.OnExternalEvent();
    }
    std::cout << deltaTime << std::endl;
    animationTimer += deltaTime;
    if(animationTimer >= 800) AnimateFlag();
}

//TODO: Box2d collission detection;
bool FlagScript::PlayerEntered() {
    return false;
//    return _player.transform.position.x > _flag.transform.position.x;
}

void FlagScript::AnimateFlag() {
    _flag.sprites.at("Default").active = !_flag.sprites.at("Default").active;
    _flag.sprites.at("Wave").active = !_flag.sprites.at("Wave").active;
    animationTimer = 0;
}

