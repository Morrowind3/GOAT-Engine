#include <chrono>
#include <random>
#include "Script_Hawk.hpp"
#include "../../../Keys.hpp"

void Script_Hawk::onTriggerEnter2D(GameObject& other) {
    //damage player
    if(other.hasTag(Keys::PLAYER)) {
        other.behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->onExternalEvent();
    }

    //if going down and touching a tile or player, go back up
    if (_direction == DOWN && (other.hasTag(Keys::SOLID) || other.hasTag(Keys::WALL) || other.hasTag(Keys::PLAYER))) {
        _direction = UP;
    }
}

void Script_Hawk::onUpdate(double deltaTime) {
    this->updateDirection();
    this->updatePosition();
    this->updateSprite();
}

void Script_Hawk::updateDirection() {

    //if going up, and reaching original height, resume idling
    if (_direction == UP && _self.transform.position.y <= _startingPos.y) {
        _direction = RIGHT;
        _circledAfterDiveCounter = 0;
        //safeguard so hawk cant dive too deep
    } else if (_direction == DOWN && (_self.transform.position.y - _startingPos.y > MAX_DIVE_DEPTH)) {
        _direction = UP;
    };

    //if idling and has circled x times, DIVE_CHANGE change to dive
    if ((_direction == LEFT || _direction == RIGHT) && _circledAfterDiveCounter >= CIRCLES_BEFORE_DIVE) {
        if (Script_Hawk::getRandomBetween(0, 1000) < DIVE_CHANGE) {
            //TODO Play sound when diving
            _direction = DOWN;
        }
    }

    //if flying furter than scope, change direction
    if (_direction == RIGHT && (_self.transform.position.x - _startingPos.x >= FLYING_SCOPE)) {
        _direction = LEFT;
        _circledAfterDiveCounter++;
    }
    if (_direction == LEFT && _self.transform.position.x <= _startingPos.x) {
        _direction = RIGHT;
        _circledAfterDiveCounter++;
    }
}

void Script_Hawk::updatePosition() {

    switch (_direction) {
        case RIGHT:
            _self.rigidBody.forceX += SPEED_IDLE;
            break;
        case LEFT:
            _self.rigidBody.forceX -= SPEED_IDLE;
            break;
        case DOWN:
            _self.rigidBody.forceY -= SPEED_DIVING;
            break;
        case UP:
            _self.rigidBody.forceY += SPEED_RISING;
            break;
    }
}

void Script_Hawk::updateSprite() {

    if (_direction == LEFT) _self.transform.flip = FLIP::FLIP_NONE;
    if (_direction == RIGHT) _self.transform.flip = FLIP::FLIP_HORIZONTAL;

    if (_direction == LEFT || _direction == RIGHT) {
        _self.sprites.at(Keys::ATTACK1).active = false;

        if (_updateCounter % 40 == 1) {
            if (_self.sprites.at(Keys::MOVE1).active) {
                _self.sprites.at(Keys::MOVE1).active = false;
                _self.sprites.at(Keys::MOVE2).active = true;
            } else {
                _self.sprites.at(Keys::MOVE1).active = true;
                _self.sprites.at(Keys::MOVE2).active = false;
            }
        }
    }
    if (_direction == DOWN) {
        _self.sprites.at(Keys::MOVE1).active = false;
        _self.sprites.at(Keys::MOVE2).active = false;
        _self.sprites.at(Keys::ATTACK1).active = true;
    }
    if (_direction == UP) {
        _self.sprites.at(Keys::ATTACK1).active = false;

        if (_updateCounter % 10 == 1) {
            if (_self.sprites.at(Keys::MOVE1).active) {
                _self.sprites.at(Keys::MOVE1).active = false;
                _self.sprites.at(Keys::MOVE2).active = true;
            } else {
                _self.sprites.at(Keys::MOVE1).active = true;
                _self.sprites.at(Keys::MOVE2).active = false;
            }
        }
    }

    _updateCounter++;
}

int Script_Hawk::getRandomBetween(int from, int to) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> random(from, to);
    return random(generator);
}