#include "Script_Goat.hpp"
#include "../../../Keys.hpp"

void Script_Goat::onTriggerEnter2D(GameObject& other) {
    if (other.tags.find(Keys::PLAYER) != other.tags.end()) {
        other.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
    }
}

void Script_Goat::onUpdate(double deltaTime) {
    _isAngry = detectsPlayer();

    if (!_isAngry) _wasAngryLastFrame = false;
    if(_isAngry && !_wasAngryLastFrame) {
        _wasAngryLastFrame = true;
        _goat.audioSources.find(Keys::BLEATHING)->second.queueForPlay = true;
    }

    updateDirection();
    updatePosition();
    updateSprite();
}

void Script_Goat::updateDirection() {
    //if angry, but walking wrong direction, switch direction
    if(_isAngry) {
        if(_player.transform.position.x < _goat.transform.position.x && _direction == GoatDirection::RIGHT) _direction = GoatDirection::LEFT;
        if(_player.transform.position.x > _goat.transform.position.x && _direction == GoatDirection::LEFT) _direction = GoatDirection::RIGHT;
    }

    //if stuck for 200 ms, switch direction
    if(_previousPos.x == _goat.transform.position.x && _previousPos.y == _goat.transform.position.y) {
        if(_stuckTimer > 200) {
            if(_direction == GoatDirection::RIGHT) _direction = GoatDirection::LEFT;
            else _direction = GoatDirection::RIGHT;
        } else {
            _stuckTimer++;
        }
    } else {
        _stuckTimer = 0;
    }

    //if reached max path length, switch direction
    if (_direction == GoatDirection::LEFT && abs(_startPosition.x - _goat.transform.position.x) >= PATH_LENGTH) {
        _direction = GoatDirection::RIGHT;
    }
    //if reached startposition, switch direction
    if (_direction == GoatDirection::RIGHT && _startPosition.x-50 <= _goat.transform.position.x) {
        _direction = GoatDirection::LEFT;
    }
}

void Script_Goat::updatePosition() {
    float speed = _isAngry ? SPEED_ANGRY : SPEED_IDLE;

    if (_direction == GoatDirection::LEFT) _goat.rigidBody.forceX = -speed;
    if (_direction == GoatDirection::RIGHT) _goat.rigidBody.forceX = speed;
    if (_globals.sceneExists(Keys::GOAT_FLIP)) _goat.rigidBody.forceY = FLIP_FORCE;

    _previousPos = _goat.transform.position;
}

void Script_Goat::updateSprite() {
    if (_globals.sceneExists(Keys::GOAT_FLIP)) {
        if (_direction == GoatDirection::LEFT) _goat.transform.flip = FLIP::FLIP_VERTICAL;
        if (_direction == GoatDirection::RIGHT) _goat.transform.flip = FLIP::FLIP_HORIZONTAL_VERTICAL;
    } else {
        if (_direction == GoatDirection::LEFT) _goat.transform.flip = FLIP::FLIP_NONE;
        if (_direction == GoatDirection::RIGHT) _goat.transform.flip = FLIP::FLIP_HORIZONTAL;
    }

    int spriteChangeSpeed = _isAngry ? 10 : 50;

    if (_walkingSwitchFrameCounter % spriteChangeSpeed == 1) {
        if (_isAngry) {
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
    return _player.transform.position.x >= _goat.transform.position.x - SENSOR_WIDTH / 2 &&
           _player.transform.position.x <= _goat.transform.position.x + SENSOR_WIDTH / 2 &&
           _player.transform.position.y >= _goat.transform.position.y - SENSOR_WIDTH / 2 &&
           _player.transform.position.y <= _goat.transform.position.y + SENSOR_WIDTH / 2;
}
