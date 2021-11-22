#include "SlabTileScript.hpp"

SlabTileScript::SlabTileScript(SlabTile& self, bool active) : Script(active), _self{self}, _input{Input::getInstance()} { }

void SlabTileScript::OnUpdate(double deltaTime) {
    if(_input.GetKeyDown(Input::KeyCode::A)) {
        //rotate left
        _self.transform.rotation -= 1;
    }
    if(_input.GetKeyDown(Input::KeyCode::D)) {
        //rotate right
        _self.transform.rotation += 1;
    }
}