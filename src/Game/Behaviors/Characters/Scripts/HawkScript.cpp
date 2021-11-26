#include "HawkScript.hpp"
#include "../../../Keys.hpp"

HawkScript::HawkScript(Hawk& self, bool active) : Script(active), _self(self), _startingPos(self.transform.position) {
    _self.transform.flip = Engine::FLIP::FLIP_HORIZONTAL;
}

void HawkScript::OnUpdate(double deltaTime) {

    if(_direction == RIGHT) {
        _self.transform.position.x += 0.8;
    }
    if(_direction == LEFT) {
        _self.transform.position.x -= 0.8;
    }

    // switch direction
    if(_self.transform.position.x < _startingPos.x || _self.transform.position.x - _startingPos.x > 400) {
        if(_direction == RIGHT) {
            _direction = LEFT;
            _self.transform.flip = Engine::FLIP::FLIP_NONE;
        } else {
            _direction = RIGHT;
            _self.transform.flip = Engine::FLIP::FLIP_HORIZONTAL;
        }
    }

    //switch move sprite
    if(_updateCounter%50 == 1) {
        if(_self.sprites.at(Keys::MOVE1).active) {
            _self.sprites.at(Keys::MOVE1).active = false;
            _self.sprites.at(Keys::MOVE2).active = true;
        } else {
            _self.sprites.at(Keys::MOVE1).active = true;
            _self.sprites.at(Keys::MOVE2).active = false;
        }
    }
    _updateCounter++;
}