#include "FlagScript.hpp"
#include "../../../Keys.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

FlagScript::FlagScript(bool active, VictoryFlag& flag, const std::shared_ptr<Player>& player) : Script(active), _flag(flag), _player(player) {
}
void FlagScript::onUpdate(double deltaTime) {
    if(playerEntered()) Globals::getInstance().gameStore(Keys::GAMESTATE, Keys::GAMESTATE_VICTORY);

    animationTimer += deltaTime;
    if(animationTimer >= 800) animateFlag();
}

//TODO: Box2d collision detection;
bool FlagScript::playerEntered() {
    return false;
//    return _player->transform.position.x + 50 > _flag.transform.position.x && _player->transform.position.x < _flag.transform.position.x + 50;
}

void FlagScript::animateFlag() {
    _flag.sprites.at("Default").active = !_flag.sprites.at("Default").active;
    _flag.sprites.at("Wave").active = !_flag.sprites.at("Wave").active;
    animationTimer = 0;
}

