#include "QuitGameScript.hpp"
#include "../../../Engine/Utilities/Input.hpp"
#include "../../../Engine/Utilities/Debug.hpp"

QuitGameScript::QuitGameScript(bool active) : Script(active) {
}

void QuitGameScript::OnExternalEvent() {
    Input::getInstance().QueueQuitEvent();
    Debug::getInstance().log("Quit game called");
}
