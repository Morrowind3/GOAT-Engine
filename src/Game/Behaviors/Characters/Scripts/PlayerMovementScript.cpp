#include "PlayerMovementScript.hpp"
#include "../../../Keys.hpp"

PlayerMovementScript::PlayerMovementScript(Player& player, bool active) : Script(active), _player{player} {
}

void PlayerMovementScript::OnUpdate(double deltaTime) {
    //TODO remove this, this is no REAL pause, because box2d slides you further, and other entities must be taken accounted for
    if (_globals.sceneGet(Keys::PAUSE) == Keys::TRUE) return; // Don't allow when paused

    bool moveLeft = _input.GetKey(KeyCode::A);
    bool moveRight = _input.GetKey(KeyCode::D);
    bool moveUp = _input.GetKeyDown(KeyCode::SPACE);

    // Decide flipping
    if (moveLeft) {
        _player.rigidBody.forceX = -PLAYER_SPEED;
        _player.transform.flip = Engine::FLIP::FLIP_HORIZONTAL;
    }
    if (moveRight) {
        _player.rigidBody.forceX = PLAYER_SPEED;
        _player.transform.flip = Engine::FLIP::FLIP_NONE;
    }

    if(moveUp) {
        _player.rigidBody.forceY = 50000;
        //TODO Player is in jumpstate, can only jump twice untill landed on ground
        _player.sprites.at(Keys::IDLE).active = false;
        _player.sprites.at(Keys::JUMP).active = true;
        _player.sprites.at(Keys::MOVE1).active = false;
        _player.sprites.at(Keys::MOVE2).active = false;
    } else {

        if(!moveRight && !moveLeft) {
            _player.sprites.at(Keys::IDLE).active = true;
            _player.sprites.at(Keys::JUMP).active = false;
            _player.sprites.at(Keys::MOVE1).active = false;
            _player.sprites.at(Keys::MOVE2).active = false;
        }

        if((moveLeft || moveRight) && _counter%20 == 1) {
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

            if (_jumpStepAltSfx) {
                _player.audioSources.at(Keys::WALK_SFX_A).queueForPlay = true;
                _jumpStepAltSfx = false;
            } else {
                _player.audioSources.at(Keys::WALK_SFX_B).queueForPlay = true;
                _jumpStepAltSfx = true;
            }
        }

        _counter++;
    }
}
