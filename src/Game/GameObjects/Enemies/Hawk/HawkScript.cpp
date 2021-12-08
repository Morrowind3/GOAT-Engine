#include <chrono>
#include <random>
#include "HawkScript.hpp"
#include "../../../Keys.hpp"

void HawkScript::onTriggerEnter2D(GameObject& other) {
    //if going down and touching a tile or player, go back up
    if (_direction == DOWN && (other.hasTag(Keys::TILE) || other.hasTag(Keys::PLAYER))) {
        _direction = UP;
    }
}

void HawkScript::onUpdate(double deltaTime) {
    this->updateDirection();
    this->updatePosition();
    this->updateSprite();
}

void HawkScript::updateDirection() {

    //if going up, and reaching original height, resume idling
    if(_direction == UP && _self.transform.position.y <= _startingPos.y) {
        _direction = RIGHT;
    } else if(_direction == DOWN && (_self.transform.position.y - _startingPos.y > 200)) {
        _direction = UP;
    };

    //if idling, DIVE_CHANGE change to dive
    if(_direction == LEFT || _direction == RIGHT) {
        if (HawkScript::getRandomBetween(0, 100) < DIVE_CHANGE) {
            _direction = DOWN;
        }
    }

    //if flying furter than scope, change direction
    if (_direction == RIGHT && (_self.transform.position.x - _startingPos.x >= FLYING_SCOPE)) {
        _direction = LEFT;
    }
    if (_direction == LEFT && _self.transform.position.x <= _startingPos.x) {
        _direction = RIGHT;
    }
}

void HawkScript::updatePosition() {

    switch (_direction) {
        case RIGHT:
//            _self.transform.position.x += SPEED_IDLE;
            _self.rigidBody.forceX += SPEED_IDLE;
            break;
        case LEFT:
//            _self.transform.position.x -= SPEED_IDLE;
            _self.rigidBody.forceX -= SPEED_IDLE;
            break;
        case DOWN:
//            _self.transform.position.y += SPEED_DIVING;
            _self.rigidBody.forceY -= SPEED_DIVING;
            break;
        case UP:
//            _self.transform.position.y -= SPEED_RISING;
            _self.rigidBody.forceY += SPEED_RISING;
            break;
    }
}

void HawkScript::updateSprite() {

    if(_direction == LEFT) {
        _self.transform.flip = FLIP::FLIP_NONE;
    }
    if(_direction == RIGHT) {
        _self.transform.flip = FLIP::FLIP_HORIZONTAL;
    }

    if (_updateCounter % 50 == 1) {
        if (_self.sprites.at(Keys::MOVE1).active) {
            _self.sprites.at(Keys::MOVE1).active = false;
            _self.sprites.at(Keys::MOVE2).active = true;
        } else {
            _self.sprites.at(Keys::MOVE1).active = true;
            _self.sprites.at(Keys::MOVE2).active = false;
        }
    }
    _updateCounter++;

    switch (_direction) {
        case RIGHT:
            _debug.log("RIGHT");
            break;
        case LEFT:
            _debug.log("LEFT");
            break;
        case DOWN:
            _debug.log("DOWN");
            break;
        case UP:
            _debug.log("UP");
            break;
    }
}

int HawkScript::getRandomBetween(int from, int to) {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> random(from, to);
    return random(generator);
}