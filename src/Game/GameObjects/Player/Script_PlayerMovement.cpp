#include "Script_PlayerMovement.hpp"
#include "../../Keys.hpp"

Script_PlayerMovement::Script_PlayerMovement(Object_Player& player, bool active) : Script(active), _player{player} {
}

/// Movement
void Script_PlayerMovement::onUpdate(double deltaTime) {
    if (_engineCalls.isPaused()) return; // Disallow any changes in the movement state while paused
    if (_pickUpTrashTimer > 0) _pickUpTrashTimer -= deltaTime; // Trash timer

    bool moveLeftKey = _input.getKey(KeyCode::LEFT) || _input.getKey(KeyCode::A); // Walk left
    bool moveRightKey = _input.getKey(KeyCode::RIGHT) || _input.getKey(KeyCode::D); // Walk right
    bool moveUpKey = _input.getKeyDown(KeyCode::UP) || _input.getKeyDown(KeyCode::W) || _input.getKeyDown(KeyCode::SPACE); // Jump

    _walkState = false;
    if (moveLeftKey) moveLeft(deltaTime);
    if (moveRightKey) moveRight(deltaTime);
    if (moveUpKey) {
        if (allowedToJump()) jump();
        else if (allowedToDoubleJump()) doubleJump();
    }
    if (!_walkState) resetAtNonWalkingState();
    updateSpriteState();
}

/// When colliding with a tile, Edmund has stopped jumping
void Script_PlayerMovement::onTriggerEnter2D(GameObject& other) {
    if (other.hasTag(Keys::TILE) && !other.hasTag(Keys::WALL)) {
        _doubleJumpState = _jumpState = false;
    }
}

void Script_PlayerMovement::onTriggerStay2D(GameObject& other) {
    if (other.hasTag(Keys::TRASH) && allowedToPickupTrash()) {
        pickupTrash(other);
    }
}

float Script_PlayerMovement::calculateWalkSpeed(double deltaTime) {
    if(_sprintModifier+=SPRINT_STEP > MAX_SPRINT_MODIFIER) _sprintModifier = MAX_SPRINT_MODIFIER;
    return (PLAYER_SPEED+_sprintModifier)*deltaTime;
}

void Script_PlayerMovement::moveLeft(double deltaTime) {
    _walkState = true;
    _player.rigidBody.forceX = -calculateWalkSpeed(deltaTime);
    _player.transform.flip = Engine::FLIP::FLIP_HORIZONTAL;
    playWalkSound(deltaTime);
}

void Script_PlayerMovement::moveRight(double deltaTime) {
    _walkState = true;
    _player.rigidBody.forceX = calculateWalkSpeed(deltaTime);
    _player.transform.flip = Engine::FLIP::FLIP_NONE;
    playWalkSound(deltaTime);
}

bool Script_PlayerMovement::allowedToJump() const {
    return !_jumpState;
}

void Script_PlayerMovement::jump() {
    _jumpState = true;
    _player.rigidBody.forceY = JUMP_FORCE;
    playJumpSound();
}

bool Script_PlayerMovement::allowedToPickupTrash() const {
    bool pickUpTrashKey = _input.getKeyDown(KeyCode::DOWN) || _input.getKeyDown(KeyCode::S);
    return pickUpTrashKey && _pickUpTrashTimer <= 0.0;
}

void Script_PlayerMovement::pickupTrash(GameObject& other) {
    other.behaviors.at(Keys::TRASH)->scripts.at(Keys::TRASH)->onExternalEvent();
    _pickUpTrashTimer = PICKUP_TRASH_GRACE_IN_MS;
}

bool Script_PlayerMovement::allowedToDoubleJump() const {
    return !_doubleJumpState;
}

void Script_PlayerMovement::doubleJump() {
    _doubleJumpState = true;
    jump();
    _player.rigidBody.forceY = DOUBLE_JUMP_FORCE;
}

/// First disables everything and then enables the correct sprites based on the state of the player
void Script_PlayerMovement::updateSpriteState() {
    _player.sprites.at(Keys::JUMP).active = false;
    _player.sprites.at(Keys::IDLE).active = false;
    _player.sprites.at(Keys::TRASH).active = false;
    _player.animators.at(Keys::WALKING_ANIMATOR).active = false;
    if (_jumpState) {
        hideWalkingSprites();
        _player.sprites.at(Keys::JUMP).active = true;
    }
    else if (_pickUpTrashTimer > 0.0) {
        hideWalkingSprites();
        _player.sprites.at(Keys::TRASH).active = true;
    }
    else if (_walkState) {
        _player.animators.at(Keys::WALKING_ANIMATOR).active = true;
    } else {
        hideWalkingSprites();
        _player.sprites.at(Keys::IDLE).active = true;
    }
    makeSurePlayerIsVisible();
}

void Script_PlayerMovement::makeSurePlayerIsVisible() {
    bool playerIsVisible = false;
    for (auto& sprite : _player.sprites) {
        if (sprite.second.active) {
            playerIsVisible = true;
            break;
        }
    }
    if (!playerIsVisible) _player.sprites.at(Keys::IDLE).active = true; // Player must be visible
}

void Script_PlayerMovement::hideWalkingSprites() {
    for (auto& walkingSprite: _player.animators.at(Keys::WALKING_ANIMATOR).sprites) {
        walkingSprite->active = false;
    }
}

/// Play the set amount of walking sounds per second
void Script_PlayerMovement::playWalkSound(double deltaTime) {
    _walkingSoundCounter+=deltaTime;
    if (!_jumpState && _walkingSoundCounter >= WALK_SOUND_PER_MS_AMOUNT) {
        _walkingSoundCounter = 0;
        if (_walkingStepAltSfx) {
            _player.audioSources.at(Keys::WALK_SFX_A).queueForPlay = true;
            _walkingStepAltSfx = false;
        } else {
            _player.audioSources.at(Keys::WALK_SFX_B).queueForPlay = true;
            _walkingStepAltSfx = true;
        }
    }
}

void Script_PlayerMovement::playJumpSound() {
    _player.audioSources.at(Keys::JUMP_SFX).queueForPlay = true;
}

/// Reset variables that are changed if the player is walking
void Script_PlayerMovement::resetAtNonWalkingState() {
    _sprintModifier = 0; // Stop sprinting if user stops walking
    _walkingSoundCounter = WALK_SOUND_PER_MS_AMOUNT; // Make sure next walking sound plays
}
