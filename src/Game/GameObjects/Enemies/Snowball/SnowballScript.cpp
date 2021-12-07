#include "SnowballScript.hpp"
#include "../../../Keys.hpp"

void SnowballScript::respawn() {
    _snowball.rigidBody.active = false;
    _snowball.transform.position = _startPosition;
}

void SnowballScript::onTriggerEnter2D(GameObject& other) {
    if(other.tags.find(Keys::PLAYER) != other.tags.end()) {
        //do damage
        other.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();

        //add force
        other.rigidBody.forceX = -1 * PUSH_FORCE;
        other.rigidBody.forceY = PUSH_FORCE;

        //disable movement and assign as paralysed
        other.behaviors.at(Keys::BEHAVIOR)->active = false;
        _paralyzedObject = other.behaviors.at(Keys::BEHAVIOR);

        //move self to startposition
        this->respawn();
    }
}

void SnowballScript::onUpdate(double deltaTime) {

    //move snowball to left
    _snowball.rigidBody.forceX = -500;

    //make gameobject rotate
    if(_spriteRotateDelayKeeper % 6 == 1) {
        _spriteRotateDelayKeeper = 1;

        _snowball.transform.rotation -= 20;

        if(_snowball.transform.rotation <= -360) {
            _snowball.transform.rotation = 0;
        }
    }
    _spriteRotateDelayKeeper++;

    //re-enable rigidbody for correct positioning
    if(!_snowball.rigidBody.active) {
        //counter needed for physics implementation to reset body
        _reactivateBodyCounter++;
        if(_reactivateBodyCounter == 6) {
            _reactivateBodyCounter = 0;
            _snowball.rigidBody.active = true;
        }
    }

    //if stuck, respawn
    Point currentPos = _snowball.transform.position;
    if(_prevPos.y == currentPos.y && _prevPos.x == currentPos.x) {
        //counter needed ... dont know exactly why, but must be bigger than _reactivateBodyCounter or else snowball stays stuck
        //after respawn
        _stuckCounter++;
        if(_stuckCounter == 10) {
            _stuckCounter = 0;
            this->respawn();
        }
    } else {
        _prevPos = currentPos;
    }

    //handle paralyzation
    if(_paralyzedObject == nullptr) return;
    _paralyzedDuration++;

    //enable movement again when PARALYZE_DURATION ends
    if(_paralyzedDuration > PARALYZE_DURATION) {
        _paralyzedDuration = 0;
        _paralyzedObject->active = true;
        _paralyzedObject.reset();
    }
}