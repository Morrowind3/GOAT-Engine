//
// Created by Morrowind3 on 26/11/2021.
//

#include "DamageScript.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Keys.hpp"
#include <iostream>

//TODO: Find a way to connect this script with the health counter script and defeat menu to avoid polling.
// Observer pattern??

void DamageScript::OnExternalEvent() {
    if(_graceTimer < GRACE_PERIOD) return;
    std::cout << "Ouch!" << std::endl;
    _actor.audioSources.at(Keys::DAMAGE_SFX).queueForPlay = true;

    int currentHealth = std::stoi(Globals::GetInstance().sceneGet(Keys::HP));
    Globals::GetInstance().sceneStore(Keys::HP, std::to_string(--currentHealth));
    _graceTimer = 0;
    if(currentHealth <= 0){
        _actor.audioSources.at(Keys::DEATH_SFX).queueForPlay = true;
        Globals::GetInstance().gameStore(Keys::GAMESTATE, Keys::GAMESTATE_DEFEAT);
    }

}

void DamageScript::OnUpdate(double deltaTime) {
    if(_graceTimer >= GRACE_PERIOD){
        _actor.transform.visible = true;
        return;
    }
    _graceTimer += deltaTime;

    //Blink for damage feedback. Numbers are arbitrary, can be made prettier by a maths nerd.
    if((int) _graceTimer % (GRACE_PERIOD / 6) < 25 ) {
        _actor.transform.visible = !_actor.transform.visible;
    }
}

void DamageScript::OnDestroy() {
    _actor.transform.visible = true;
}

