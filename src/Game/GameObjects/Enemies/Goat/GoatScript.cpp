#include "GoatScript.hpp"
#include "../../../Keys.hpp"

void GoatScript::onTriggerEnter2D(GameObject& other) {
    if (other.tags.find(Keys::PLAYER) != other.tags.end()) {
        other.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
        _goat.audioSources.find(Keys::BLEATHING)->second.queueForPlay = true;
    }
}

void GoatScript::onUpdate(double deltaTime) {
    this->updateDirection();
    this->updatePosition();
    this->updateSprite();
}

void GoatScript::updateDirection() {
    if(_direction == LEFT && abs(_startPosition.x - _goat.transform.position.x) > PATH_LENGTH) {
        _direction = RIGHT;
    }
    if(_direction == RIGHT && _startPosition.x < _goat.transform.position.x) {
        _direction = LEFT;
    }
}

void GoatScript::updatePosition() {
    if(_direction == LEFT) _goat.rigidBody.forceX = -SPEED_ANGRY;
    if(_direction == RIGHT) _goat.rigidBody.forceX = SPEED_IDLE;
}

void GoatScript::updateSprite() {
    if (_direction == LEFT) _goat.transform.flip = FLIP::FLIP_NONE;
    if (_direction == RIGHT) _goat.transform.flip = FLIP::FLIP_HORIZONTAL;

    //TODO Animators

    switch (_direction) {
        case LEFT:
            if(_walkingSwitchFrameCounter % 10 == 1) {
                _goat.sprites.at(Keys::IDLE).active = false;
                _goat.sprites.at(Keys::IDLE2).active = false;
                if (_goat.sprites.at(Keys::ATTACK1).active) {
                    _goat.sprites.at(Keys::ATTACK1).active = false;
                    _goat.sprites.at(Keys::ATTACK2).active = true;
                } else {
                    _goat.sprites.at(Keys::ATTACK1).active = true;
                    _goat.sprites.at(Keys::ATTACK2).active = false;
                }
            }
            break;
        case RIGHT:
            if(_walkingSwitchFrameCounter % 50 == 1) {
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
            break;
    }

    _walkingSwitchFrameCounter++;
}