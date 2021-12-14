#include "Script_Trash.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../Keys.hpp"
#include <iostream>

void Script_Trash::onExternalEvent() {
    int currentTrash = Globals::getInstance().sceneExists(Keys::TRASH) ? std::stoi(Globals::getInstance().sceneGet(Keys::TRASH)) : 0;
    Globals::getInstance().sceneStore(Keys::TRASH, std::to_string(++currentTrash));
    _trash.audioSources.at(Keys::TRASH).queueForPlay = true;
    _queueForDeactivation = true;
}

void Script_Trash::onUpdate(double deltaTime) {
    // TODO: Play sound with onDestroy instead of this hacky method
    if(_queueForDeactivation){
        _deactivationTimer += deltaTime;
    } else return;
    if (_deactivationTimer + deltaTime > 300) {
        _trash.active = false;
    }
}
