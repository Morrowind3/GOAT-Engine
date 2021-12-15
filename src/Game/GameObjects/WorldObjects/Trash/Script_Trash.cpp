#include "Script_Trash.hpp"
#include "../../../Keys.hpp"

Script_Trash::Script_Trash(Object_Trash& trash, bool active) : Script(active), _trash(trash){}

void Script_Trash::onExternalEvent() {
    int currentTrash = std::stoi(_globals.gameGet(Keys::TRASH));
    _globals.gameStore(Keys::TRASH, std::to_string(++currentTrash));
    _trash.audioSources.at(Keys::TRASH).queueForPlay = true;
    _trash.queueForDestruction = true;
}

