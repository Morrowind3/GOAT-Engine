//
// Created by Morrowind3 on 05/12/2021.
//

#include "TrashScript.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Keys.hpp"
#include <iostream>

void TrashScript::onExternalEvent() {
    int currentTrash = Globals::getInstance().sceneExists(Keys::TRASH) ? std::stoi(Globals::getInstance().sceneGet(Keys::TRASH)) : 0;
    Globals::getInstance().sceneStore(Keys::TRASH, std::to_string(++currentTrash));
    _trash.audioSources.at(Keys::TRASH).queueForPlay = true;
    _queueForDeactivation = true;
}

void TrashScript::onUpdate(double deltaTime) {
    // TODO: Play sound with onDestroy instead of this hacky method
    if(_queueForDeactivation){
        _deactivationTimer += deltaTime;
    } else return;
    if (_deactivationTimer + deltaTime > 300) {
        _trash.active = false;
    }
}
