#include "FlagScript.hpp"
#include "../../../Keys.hpp"

FlagScript::FlagScript(bool active, VictoryFlag& flag, const std::shared_ptr<Player>& player) : Script(active), _flag(flag), _player(player) {
}
void FlagScript::OnUpdate(double deltaTime) {
    if(PlayerEntered()){
        _player->behaviors.at(Keys::BEHAVIOR)->scripts.at(Keys::DAMAGE)->OnExternalEvent();
//        VictoryScript victoryScript(true);
//        victoryScript.OnStart();
    }
    animationTimer += deltaTime;
    if(animationTimer >= 800) AnimateFlag();
}

//TODO: Box2d collision detection;
bool FlagScript::PlayerEntered() {
    return _player->transform.position.x + 50 > _flag.transform.position.x && _player->transform.position.x < _flag.transform.position.x + 50;
}

void FlagScript::AnimateFlag() {
    _flag.sprites.at("Default").active = !_flag.sprites.at("Default").active;
    _flag.sprites.at("Wave").active = !_flag.sprites.at("Wave").active;
    animationTimer = 0;
}

