#include "Script_SceneInit.hpp"
#include "../../../Keys.hpp"

Script_SceneInit::Script_SceneInit(unsigned short currentEtappe, unsigned short startHp, bool active):
    Script(active), _currentEtappe{currentEtappe}, _startHp{startHp} {
}

/// Sets variables so the scene state is reset
void Script_SceneInit::onStart() {
    _globals.gameStore(Keys::CURRENT_ETAPPE, std::to_string(_currentEtappe));
    _globals.gameStore(Keys::TRASH, std::to_string(0));
    _globals.gameStore(Keys::HP, std::to_string(_startHp));
}
