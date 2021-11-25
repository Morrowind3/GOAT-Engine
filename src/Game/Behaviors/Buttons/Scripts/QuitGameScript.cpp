#include "QuitGameScript.hpp"
#include "../../../../Engine/Utilities/Input.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"

QuitGameScript::QuitGameScript(bool active) : Script(active) {
}

void QuitGameScript::OnExternalEvent() {
    Input::GetInstance().QueueQuitEvent();
    Debug::GetInstance().log("Quit game called");
}
