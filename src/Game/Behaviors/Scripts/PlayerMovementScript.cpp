#include "PlayerMovementScript.hpp"

static const int PLAYER_SPEED = 4;

PlayerMovementScript::PlayerMovementScript(Player& player, bool active) : Script(active), _player{player}, _input{Input::getInstance()} {
}

void PlayerMovementScript::OnUpdate(double deltaTime) {
    bool moveLeft = _input.GetKeyDown(Input::KeyCode::A);
    bool moveRight = _input.GetKeyDown(Input::KeyCode::D);

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
    if (moveLeft || moveRight) _player.activeSprite = &_player.sprites.at(PLAYER::MOVE1);
    else _player.activeSprite = &_player.sprites.at(PLAYER::IDLE);
}
