#include "DebugToggleScript.hpp"

DebugToggleScript::DebugToggleScript(bool active) : Script(active) {
}

void DebugToggleScript::onExternalEvent() {
    _debug.toggle(!_debug.isActive());
}
