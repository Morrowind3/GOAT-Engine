#include "PlayerMovementScript.hpp"

PlayerMovementScript::PlayerMovementScript(Player& player, bool active) : Script(active), _player{player}, _input{Input::getInstance()} {
}

void PlayerMovementScript::OnUpdate(double deltaTime) {
    bool moveLeft = _input.GetKeyDown(Input::KeyCode::A);
    bool moveRight = _input.GetKeyDown(Input::KeyCode::D);
    bool moveUp = _input.GetKeyDown(Input::KeyCode::W);

    // Perform movement
    if (moveRight) {
        _player.transform.position.x += PLAYER_SPEED;
        _player.transform.flip = Engine::FLIP::FLIP_NONE;
    }
    if (moveLeft) {
        _player.transform.position.x-=PLAYER_SPEED;
        _player.transform.flip = Engine::FLIP::FLIP_HORIZONTAL;
    }

    // Show correct sprite
    if (moveLeft || moveRight) {
        _player.sprites.at(PLAYER::JUMP).active = false;
        _player.sprites.at(PLAYER::MOVE1).active = true;
        _player.sprites.at(PLAYER::IDLE).active = false;

        if (_jumpStepAltSfx) {
            _player.audioSources.at(PLAYER::WALK_SFX_A).queueForPlay = true;
            _jumpStepAltSfx = false;
        } else {
            _player.audioSources.at(PLAYER::WALK_SFX_B).queueForPlay = true;
            _jumpStepAltSfx = true;
        }

    }
    else {
        _player.sprites.at(PLAYER::JUMP).active = false;
        _player.sprites.at(PLAYER::MOVE1).active = false;
        _player.sprites.at(PLAYER::IDLE).active = true;
    }
}
