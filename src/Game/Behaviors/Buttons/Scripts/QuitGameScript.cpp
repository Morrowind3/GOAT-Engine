#include "QuitGameScript.hpp"
#include "../../../../Engine/Utilities/Input.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"

QuitGameScript::QuitGameScript(bool active) : Script(active) {
}

void QuitGameScript::onExternalEvent() {
    Input::getInstance().queueQuitEvent();
    Debug::getInstance().log("Quit game called");
}
