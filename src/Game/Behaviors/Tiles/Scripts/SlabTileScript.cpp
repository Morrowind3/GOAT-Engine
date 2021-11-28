#include "SlabTileScript.hpp"

SlabTileScript::SlabTileScript(SlabTile& self, bool active) : Script(active), _self{self}, _input{Input::GetInstance()} { }

void SlabTileScript::OnUpdate(double deltaTime) {
    //example usage of tilescript
//    if(_input.GetKeyDown(KeyCode::A)) {
//        //rotate left
//        _self.transform.rotation -= 1;
//    }
//    if(_input.GetKeyDown(KeyCode::D)) {
//        //rotate right
//        _self.transform.rotation += 1;
//    }
}