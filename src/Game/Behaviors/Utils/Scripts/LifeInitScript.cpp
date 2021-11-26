#include "LifeInitScript.hpp"
#include "../../../Keys.hpp"

LifeInitScript::LifeInitScript(int startHp, bool active) : Script(active), _startHp{startHp} {
}

void LifeInitScript::OnStart() {
    if (!_globals.sceneExists(Keys::HP)) _globals.sceneStore(Keys::HP, std::to_string(_startHp));
}
