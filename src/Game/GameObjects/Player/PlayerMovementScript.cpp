#include "PlayerMovementScript.hpp"
#include "../../Keys.hpp"

PlayerMovementScript::PlayerMovementScript(Player& player, bool active) : Script(active), _player{player} {
}

/// Movement
void PlayerMovementScript::onUpdate(double deltaTime) {
    if (_engineCalls.isPaused()) return; // Disallow any changes in the movement state while paused

    bool moveLeftKey = _input.getKey(KeyCode::LEFT) || _input.getKey(KeyCode::A); // Walk left
    bool moveRightKey = _input.getKey(KeyCode::RIGHT) || _input.getKey(KeyCode::D); // Walk right
    bool moveUpKey = _input.getKeyDown(KeyCode::UP) || _input.getKeyDown(KeyCode::W) || _input.getKeyDown(KeyCode::SPACE); // Jump
    bool moveDownKey = _input.getKey(KeyCode::DOWN) || _input.getKeyDown(KeyCode::S); // Pick up trash

    if (moveLeftKey) moveLeft(deltaTime);
    if (moveRightKey) moveRight(deltaTime);
    if (moveUpKey) {
        if (allowedToJump()) jump(deltaTime);
        else if (allowedToDoubleJump(deltaTime)) doubleJump(deltaTime);
    }
    if (!moveLeftKey && !moveRightKey) _sprintModifier = 0; // Stop sprinting if user stops walking
    if (allowedToJump()) updateSpriteStateWhileWalking(moveLeftKey, moveRightKey); // Only update in non-jump mode
    _yPositionLastFrame = _player.transform.position.y;
}

/// When colliding with a tile, Edmund has stopped jumping
/// Indirectly allows him to climb a steep wall by colliding with the side of the wall
void PlayerMovementScript::onTriggerEnter2D(GameObject& other) {
    if (other.hasTag(Keys::TILE)) {
        _doubleJumpState = _jumpState = false;
    }
}

float PlayerMovementScript::calculateWalkSpeed(double deltaTime) {
    if(_sprintModifier+=SPRINT_STEP > MAX_SPRINT_MODIFIER) _sprintModifier = MAX_SPRINT_MODIFIER;
    return (PLAYER_SPEED+_sprintModifier)/deltaTime;
}

void PlayerMovementScript::moveLeft(double deltaTime) {
    _player.rigidBody.forceX = -calculateWalkSpeed(deltaTime);
    _player.transform.flip = Engine::FLIP::FLIP_HORIZONTAL;
}

void PlayerMovementScript::moveRight(double deltaTime) {
    _player.rigidBody.forceX = calculateWalkSpeed(deltaTime);
    _player.transform.flip = Engine::FLIP::FLIP_NONE;
}

bool PlayerMovementScript::allowedToJump() const {
    return !_jumpState;
}

void PlayerMovementScript::jump(double deltaTime) {
    _jumpState = true;
    _player.rigidBody.forceY = JUMP_FORCE/deltaTime;
    _player.sprites.at(Keys::IDLE).active = false;
    _player.sprites.at(Keys::JUMP).active = true;
    _player.sprites.at(Keys::MOVE1).active = false;
    _player.sprites.at(Keys::MOVE2).active = false;
    playJumpSound();
}

bool PlayerMovementScript::allowedToDoubleJump(double deltaTime) const {
    return !_doubleJumpState && _player.transform.position.y - _yPositionLastFrame < DOUBLE_JUMP_TRIGGER * deltaTime;
}

void PlayerMovementScript::doubleJump(double deltaTime) {
    _doubleJumpState = true;
    jump(deltaTime);
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
