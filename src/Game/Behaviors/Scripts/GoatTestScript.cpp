#include "GoatTestScript.hpp"
#include <iostream>

GoatTestScript::GoatTestScript(GameObject& self, bool active) : Script(active), _self{self}, _input{Input::getInstance()} {
}

void GoatTestScript::OnStart() {
}

void GoatTestScript::OnUpdate(double deltaTime) {
    if (_input.GetKeyDown(Input::KeyCode::D)) _self.transform.position.x+=10;
    if (_input.GetKeyDown(Input::KeyCode::A)) _self.transform.position.x-=10;
    if (_input.GetKeyDown(Input::KeyCode::W)) _self.transform.position.y-=10;
    if (_input.GetKeyDown(Input::KeyCode::S)) _self.transform.position.y+=10;
}

void GoatTestScript::OnDestroy() {

}
