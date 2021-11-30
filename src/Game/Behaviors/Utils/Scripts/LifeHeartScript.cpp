#include "LifeHeartScript.hpp"
#include "../../../Keys.hpp"

LifeHeartScript::LifeHeartScript(int filledAtHp, LifeHeart& lifeHeart, bool active):
        Script(active), _lifeHeart{lifeHeart}, _filledAtHp{filledAtHp} {
}

void LifeHeartScript::onUpdate(double deltaTime) {
    //TODO: It's more efficient to move this to OnExternalEvent and letting DamageScript call it.
    int queryValue = std::stoi(_globals.sceneGet(Keys::HP));
    if (_lastQueryValue != queryValue) {
        _lastQueryValue = queryValue;
        if (_lastQueryValue >= _filledAtHp) { // Check if heart should be filled
            _lifeHeart.sprites.at(Keys::TRUE).active = true;
            _lifeHeart.sprites.at(Keys::FALSE).active = false;
        } else {
            _lifeHeart.sprites.at(Keys::TRUE).active = false;
            _lifeHeart.sprites.at(Keys::FALSE).active = true;
        }
    }
}
