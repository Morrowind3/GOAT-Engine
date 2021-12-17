#include "Script_OnClickSound.hpp"

Script_OnClickSound::Script_OnClickSound(AudioSource& clickSound, bool active): Script(active), _clickSound{clickSound} {
}

void Script_OnClickSound::onExternalEvent() {
    _clickSound.queueForPlay = true;
}


