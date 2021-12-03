#include "SnakeScript.hpp"
#include "../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../Keys.hpp"

void SnakeScript::onTriggerEnter2D(GameObject& other) {
    if(other.tags.find(Keys::PLAYER) != other.tags.end()) {
        //do damage
        other.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();

        //add force
        other.rigidBody.forceX = -1 * PUSH_FORCE;
        other.rigidBody.forceY = PUSH_FORCE;

        //disable movement and assign as paralysed
        other.behaviors.at(Keys::BEHAVIOR)->active = false;
        _paralyzedObject = other.behaviors.at(Keys::BEHAVIOR);

        //change sprite
        _snake.sprites.at(Keys::IDLE).active = false;
        _snake.sprites.at(Keys::ATTACK1).active = true;

        //make sound
        _snake.audioSources.find(Keys::BLEATHING)->second.queueForPlay = true;
    }
}

void SnakeScript::onUpdate(double deltaTime) {
    if(_paralyzedObject == nullptr) return;

    _paralyzedDuration++;

    //enable movement again when PARALYZE_DURATION ends
    if(_paralyzedDuration > PARALYZE_DURATION) {
        _paralyzedDuration = 0;
        _paralyzedObject->active = true;
        _paralyzedObject.reset();
        _snake.sprites.at(Keys::IDLE).active = true;
        _snake.sprites.at(Keys::ATTACK1).active = false;
    }
}