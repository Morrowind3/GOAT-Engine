#include "GoatScript.hpp"
#include "../../../Keys.hpp"

void GoatScript::onTriggerEnter2D(GameObject& other) {
    if(other.tags.find(Keys::PLAYER) != other.tags.end()) {
        other.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
        _goat.audioSources.find(Keys::BLEATHING)->second.queueForPlay = true;
    }
}

void GoatScript::onUpdate(double deltaTime) {

    // make goat walk until pathlength, then turn around
    if(abs(_startPosition.x - _goat.transform.position.x) > _pathLength && _direction == 0) switchDirection();
    // make goat walk until startposition, then turn around
    if(_startPosition.x < _goat.transform.position.x && _direction == 1) switchDirection();

    // add speed
    switch (_direction) {
        case 0:
            _goat.rigidBody.forceX = -_angrySpeed;
            break;
        case 1:
            _goat.rigidBody.forceX = _idleSpeed;
            break;
        default:
            break;
    }

    // update sprites
    walk();
}

void GoatScript::switchDirection() {
    if(_direction == 0) {
        _direction = 1;
        _goat.transform.flip = Engine::FLIP::FLIP_HORIZONTAL;
    } else {
        _direction = 0;
        _goat.transform.flip = Engine::FLIP::FLIP_NONE;
    }
}

void GoatScript::walk() {

    int delay;
    _direction == 0 ? delay = 20 : delay = 50;

    if(_walkingSwitchFrameCounter % delay == 1) {
        _walkingSwitchFrameCounter = 1;

        switch (_direction) {
            case 0:
                _goat.sprites.at(Keys::IDLE).active = false;
                _goat.sprites.at(Keys::IDLE2).active = false;
                if(_goat.sprites.at(Keys::ATTACK1).active) {
                    _goat.sprites.at(Keys::ATTACK1).active = false;
                    _goat.sprites.at(Keys::ATTACK2).active = true;
                } else {
                    _goat.sprites.at(Keys::ATTACK1).active = true;
                    _goat.sprites.at(Keys::ATTACK2).active = false;
                }
                break;
            case 1:
                _goat.sprites.at(Keys::ATTACK1).active = false;
                _goat.sprites.at(Keys::ATTACK2).active = false;
                if(_goat.sprites.at(Keys::IDLE).active) {
                    _goat.sprites.at(Keys::IDLE).active = false;
                    _goat.sprites.at(Keys::IDLE2).active = true;
                } else {
                    _goat.sprites.at(Keys::IDLE).active = true;
                    _goat.sprites.at(Keys::IDLE2).active = false;
                }
                break;
            default:
                break;
        }
    }

    _walkingSwitchFrameCounter++;
}