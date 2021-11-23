#include "QuitGameScript.hpp"
#include "../../../Engine/Utilities/Input.hpp"

QuitGameScript::QuitGameScript(bool active) : Script(active) {
}

void QuitGameScript::OnExternalEvent() {
    Input::getInstance().QueueQuitEvent();
}
