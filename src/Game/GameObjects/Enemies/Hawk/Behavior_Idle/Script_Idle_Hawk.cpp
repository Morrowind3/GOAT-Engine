#include "Script_Idle_Hawk.hpp"
#include "../../../../Keys.hpp"

void Script_Idle_Hawk::onUpdate(double deltaTime) {
    this->updateDirection();
    this->updatePosition();
    this->updateSprite();
}

void Script_Idle_Hawk::updateDirection() {
    //if flying further than scope, change direction
    if (_direction == RIGHT && (_self.transform.position.x - _startingPos.x >= FLYING_SCOPE)) {
        _direction = LEFT;
    }
    if (_direction == LEFT && _self.transform.position.x <= _startingPos.x) {
        _direction = RIGHT;
    }
}

void Script_Idle_Hawk::updatePosition() {

    switch (_direction) {
        case RIGHT:
            _self.rigidBody.forceX += SPEED_IDLE;
            break;
        case LEFT:
            _self.rigidBody.forceX -= SPEED_IDLE;
            break;
    }
}

void Script_Idle_Hawk::updateSprite() {
    if (_direction == LEFT) _self.transform.flip = FLIP::FLIP_NONE;
    if (_direction == RIGHT) _self.transform.flip = FLIP::FLIP_HORIZONTAL;

    if (_updateCounter % 40 == 1) {
        if (_self.sprites.at(Keys::MOVE1).active) {
            _self.sprites.at(Keys::MOVE1).active = false;
            _self.sprites.at(Keys::MOVE2).active = true;
        } else {
            _self.sprites.at(Keys::MOVE1).active = true;
            _self.sprites.at(Keys::MOVE2).active = false;
        }
    }

    _updateCounter++;
}