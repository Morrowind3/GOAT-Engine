#include "PlayerMovementScript.hpp"

static const int PLAYER_SPEED = 4;

PlayerMovementScript::PlayerMovementScript(Player& player, bool active) : Script(active), _player{player}, _input{Input::getInstance()} {
}

void PlayerMovementScript::OnUpdate(double deltaTime) {
    if (_input.GetKeyDown(Input::KeyCode::D)) _player.transform.position.x+=PLAYER_SPEED;
    if (_input.GetKeyDown(Input::KeyCode::A)) _player.transform.position.x-=PLAYER_SPEED;
}
