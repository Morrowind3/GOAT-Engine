#include "Script_QuitGame.hpp"
#include "../../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../../Engine/Utilities/Debug.hpp"

Script_QuitGame::Script_QuitGame(bool active) : Script(active) {
}

void Script_QuitGame::onExternalEvent() {
    _engineCalls.queueQuitEvent();
    _debug.log("Quit game called from script");
}
