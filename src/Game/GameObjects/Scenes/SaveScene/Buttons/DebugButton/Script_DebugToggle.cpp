#include "Script_DebugToggle.hpp"

Script_DebugToggle::Script_DebugToggle(bool active) : Script(active) {
}

void Script_DebugToggle::onExternalEvent() {
    _debug.toggle(!_debug.isActive());
}
