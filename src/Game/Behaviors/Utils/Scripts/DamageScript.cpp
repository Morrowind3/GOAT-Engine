//
// Created by Morrowind3 on 26/11/2021.
//

#include "DamageScript.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Keys.hpp"
#include "GameOverScript.hpp"
#include <iostream>

void DamageScript::OnExternalEvent() {
    if(_graceTimer < GRACE_PERIOD) return;
    std::cout << "Ouch!" << std::endl;
    int currentHealth = std::stoi(Globals::GetInstance().sceneGet(Keys::HP));
    --currentHealth;
    Globals::GetInstance().sceneGet(Keys::HP) = std::to_string(currentHealth);
    _graceTimer = 0;
    if(currentHealth <= 0)  GameOverScript gameOver {true};
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
