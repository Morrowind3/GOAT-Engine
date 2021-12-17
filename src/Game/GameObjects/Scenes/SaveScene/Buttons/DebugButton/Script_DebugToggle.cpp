#include "Script_DebugToggle.hpp"

Script_DebugToggle::Script_DebugToggle(AudioSource& enableSound, AudioSource& disableSound, bool active):
    Script(active), _enableSound{enableSound}, _disableSound{disableSound} {
}

void Script_DebugToggle::onExternalEvent() {
    _debug.toggle(!_debug.isActive());
    if (_debug.isActive()) _enableSound.queueForPlay = true;
    else _disableSound.queueForPlay = true;
}
