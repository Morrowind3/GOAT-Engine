#include "Script_LifeInit.hpp"
#include "../../../Keys.hpp"

Script_LifeInit::Script_LifeInit(int startHp, bool active) : Script(active), _startHp{startHp} {
}

void Script_LifeInit::onStart() {
    if (!_globals.sceneExists(Keys::HP)) _globals.sceneStore(Keys::HP, std::to_string(_startHp));
}
