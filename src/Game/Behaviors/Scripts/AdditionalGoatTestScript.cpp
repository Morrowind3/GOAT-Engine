#include "AdditionalGoatTestScript.hpp"

AdditionalGoatTestScript::AdditionalGoatTestScript(GameObject& self, bool active) : Script(active), _self{self} {
}

void AdditionalGoatTestScript::OnUpdate(double deltaTime) {
    _self.transform.rotation++;
}
