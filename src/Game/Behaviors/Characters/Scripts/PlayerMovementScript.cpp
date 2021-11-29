#include "PlayerMovementScript.hpp"
#include "../../../Keys.hpp"

PlayerMovementScript::PlayerMovementScript(Player& player, bool active) : Script(active), _player{player} {
}

/// Movement
void PlayerMovementScript::onUpdate(double deltaTime) {
    bool moveLeftKey = _input.getKey(KeyCode::LEFT) || _input.getKey(KeyCode::A);
    bool moveRightKey = _input.getKey(KeyCode::RIGHT) || _input.getKey(KeyCode::D);
    bool moveUpKey = _input.getKey(KeyCode::UP) || _input.getKeyDown(KeyCode::W) || _input.getKeyDown(KeyCode::SPACE);
    //bool moveDownKey = _input.getKey(KeyCode::DOWN) || _input.getKeyDown(KeyCode::S); // Will be used to pick up trash

    if (moveLeftKey) moveLeft();
    if (moveRightKey) moveRight();
    if (moveUpKey) {
        if (allowedToJump()) jump();
        else if (allowedToDoubleJump(deltaTime)) doubleJump();
    }
    updateSpriteStateWhileWalking(moveLeftKey, moveRightKey);
    _yPositionLastFrame = _player.transform.position.y;
}

/// When colliding with a tile, Edmund has stopped jumping
/// Indirectly allows him to climb a steep wall by colliding with the side of the wall
void PlayerMovementScript::onTriggerEnter2D(GameObject& other) {
    if (other.hasTag(Keys::TILE)) {
        _doubleJumpState = _jumpState = false;
    }
}

void PlayerMovementScript::moveLeft() {
    _player.rigidBody.forceX = -PLAYER_SPEED;
    _player.transform.flip = Engine::FLIP::FLIP_HORIZONTAL;
}

void PlayerMovementScript::moveRight() {
    _player.rigidBody.forceX = PLAYER_SPEED;
    _player.transform.flip = Engine::FLIP::FLIP_NONE;
}

bool PlayerMovementScript::allowedToJump() const {
    return !_jumpState;
}

void PlayerMovementScript::jump() {
    _jumpState = true;
    _player.rigidBody.forceY = JUMP_FORCE;
    _player.sprites.at(Keys::IDLE).active = false;
    _player.sprites.at(Keys::JUMP).active = true;
    _player.sprites.at(Keys::MOVE1).active = false;
    _player.sprites.at(Keys::MOVE2).active = false;
    playJumpSound();
}

bool PlayerMovementScript::allowedToDoubleJump(double deltaTime) const {
    return !_doubleJumpState && _player.transform.position.y - _yPositionLastFrame < DOUBLE_JUMP_TRIGGER * deltaTime;
}

void PlayerMovementScript::doubleJump() {
    _doubleJumpState = true;
    jump();
    _player.rigidBody.forceY *= DOUBLE_JUMP_MODIFIER;
}

void PlayerMovementScript::updateSpriteStateWhileWalking(bool moveLeft, bool moveRight) {
    if (!moveRight && !moveLeft) { // Idle
        _player.sprites.at(Keys::IDLE).active = true;
        _player.sprites.at(Keys::JUMP).active = false;
        _player.sprites.at(Keys::MOVE1).active = false;
        _player.sprites.at(Keys::MOVE2).active = false;
    }
    if ((moveLeft || moveRight) && _walkingSwitchFrameCounter % 20 == 1) { // Walking
        switch (_walkingState) {
            case 0:
                _player.sprites.at(Keys::IDLE).active = true;
                _player.sprites.at(Keys::JUMP).active = false;
                _player.sprites.at(Keys::MOVE1).active = false;
                _player.sprites.at(Keys::MOVE2).active = false;
                _walkingState++;
                break;
            case 1:
                _player.sprites.at(Keys::IDLE).active = false;
                _player.sprites.at(Keys::JUMP).active = false;
                _player.sprites.at(Keys::MOVE1).active = true;
                _player.sprites.at(Keys::MOVE2).active = false;
                _walkingState++;
                break;
            case 2:
                _player.sprites.at(Keys::IDLE).active = true;
                _player.sprites.at(Keys::JUMP).active = false;
                _player.sprites.at(Keys::MOVE1).active = false;
                _player.sprites.at(Keys::MOVE2).active = false;
                _walkingState++;
                break;
            case 3:
                _player.sprites.at(Keys::IDLE).active = false;
                _player.sprites.at(Keys::JUMP).active = false;
                _player.sprites.at(Keys::MOVE1).active = false;
                _player.sprites.at(Keys::MOVE2).active = true;
                _walkingState = 0;
                break;
        }
        playWalkSound();
    }
    _walkingSwitchFrameCounter++;
}

void PlayerMovementScript::playWalkSound() {
    if (_walkingStepAltSfx) {
        _player.audioSources.at(Keys::WALK_SFX_A).queueForPlay = true;
        _walkingStepAltSfx = false;
    } else {
        _player.audioSources.at(Keys::WALK_SFX_B).queueForPlay = true;
        _walkingStepAltSfx = true;
    }
}

void PlayerMovementScript::playJumpSound() {
    _player.audioSources.at(Keys::JUMP_SFX).queueForPlay = true;
}
