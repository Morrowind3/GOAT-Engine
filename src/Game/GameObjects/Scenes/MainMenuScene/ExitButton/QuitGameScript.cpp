#include "QuitGameScript.hpp"
#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"

QuitGameScript::QuitGameScript(bool active) : Script(active) {
}

void QuitGameScript::onExternalEvent() {
    _engineCalls.queueQuitEvent();
    _debug.log("Quit game called from script");
}
