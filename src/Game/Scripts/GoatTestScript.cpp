#include "GoatTestScript.hpp"
#include <iostream>

GoatTestScript::GoatTestScript(GameObject& self, bool active) : Script(active), _self{self} {
}

void GoatTestScript::OnStart() {
    std::cout << "GoatTestScript on start!" << '\n';
}

void GoatTestScript::OnUpdate(double deltaTime) {
    _self.transform._position.x++;
    _self.transform._position.y++;
}

void GoatTestScript::OnDestroy() {
    std::cout << "GoatTestScript on destroy!" << '\n';
}
