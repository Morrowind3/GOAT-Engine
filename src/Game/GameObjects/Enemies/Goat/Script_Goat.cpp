#include "Script_Goat.hpp"
#include "../../../Keys.hpp"

void Script_Goat::onTriggerEnter2D(GameObject& other) {
    if (other.tags.find(Keys::PLAYER) != other.tags.end()) {
        other.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
    }
}

void Script_Goat::onUpdate(double deltaTime) {
    this->_isAngry = this->detectsPlayer();
    //TODO make bleathing volume lower
    if(this->_isAngry) _goat.audioSources.find(Keys::BLEATHING)->second.queueForPlay = true;

    this->updateDirection();
    this->updatePosition();
    this->updateSprite();
}

void Script_Goat::updateDirection() {
    //if angry, but walking wrong direction, switch direction
    if(this->_isAngry) {
        if(_player.transform.position.x < _goat.transform.position.x && _direction == RIGHT) _direction = LEFT;
        if(_player.transform.position.x > _goat.transform.position.x && _direction == LEFT) _direction = RIGHT;
    }

    //if stuck for 200 ms, switch direction
    if(_previousPos.x == _goat.transform.position.x && _previousPos.y == _goat.transform.position.y) {
        if(_stuckTimer > 200) {
            if(_direction == RIGHT) _direction = LEFT;
            else _direction = RIGHT;
        } else {
            _stuckTimer++;
        }
    } else {
        _stuckTimer = 0;
    }

    //if reached max path length, switch direction
    if (_direction == LEFT && abs(_startPosition.x - _goat.transform.position.x) >= PATH_LENGTH) {
        _direction = RIGHT;
    }
    //if reached startposition, switch direction
    if (_direction == RIGHT && _startPosition.x-50 <= _goat.transform.position.x) {
        _direction = LEFT;
    }
}

void Script_Goat::updatePosition() {
    float speed = this->_isAngry ? SPEED_ANGRY : SPEED_IDLE;

    if (_direction == LEFT) _goat.rigidBody.forceX = -speed;
    if (_direction == RIGHT) _goat.rigidBody.forceX = speed;

    _previousPos = _goat.transform.position;
}

void Script_Goat::updateSprite() {
    if (_direction == LEFT) _goat.transform.flip = FLIP::FLIP_NONE;
    if (_direction == RIGHT) _goat.transform.flip = FLIP::FLIP_HORIZONTAL;

    int spriteChangeSpeed = this->_isAngry ? 10 : 50;

    if (_walkingSwitchFrameCounter % spriteChangeSpeed == 1) {
        if (this->_isAngry) {
            _goat.sprites.at(Keys::IDLE).active = false;
            _goat.sprites.at(Keys::IDLE2).active = false;
            if (_goat.sprites.at(Keys::ATTACK1).active) {
                _goat.sprites.at(Keys::ATTACK1).active = false;
                _goat.sprites.at(Keys::ATTACK2).active = true;
            } else {
                _goat.sprites.at(Keys::ATTACK1).active = true;
                _goat.sprites.at(Keys::ATTACK2).active = false;
            }
        } else {
            _goat.sprites.at(Keys::ATTACK1).active = false;
            _goat.sprites.at(Keys::ATTACK2).active = false;
            if (_goat.sprites.at(Keys::IDLE).active) {
                _goat.sprites.at(Keys::IDLE).active = false;
                _goat.sprites.at(Keys::IDLE2).active = true;
            } else {
                _goat.sprites.at(Keys::IDLE).active = true;
                _goat.sprites.at(Keys::IDLE2).active = false;
            }
        }

    }

    _walkingSwitchFrameCounter++;
}

bool Script_Goat::detectsPlayer() {
    int sensorWidth{600};

    return _player.transform.position.x >= _goat.transform.position.x - sensorWidth / 2 &&
           _player.transform.position.x <= _goat.transform.position.x + sensorWidth / 2;
}