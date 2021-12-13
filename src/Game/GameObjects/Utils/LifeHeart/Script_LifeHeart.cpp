#include "Script_LifeHeart.hpp"
#include "../../../Keys.hpp"

Script_LifeHeart::Script_LifeHeart(int filledAtHp, Object_LifeHeart& lifeHeart, bool active):
        Script(active), _lifeHeart{lifeHeart}, _filledAtHp{filledAtHp} {
}

void Script_LifeHeart::onUpdate(double deltaTime) {
    //TODO: It's more efficient to move this to OnExternalEvent and letting Script_Damage call it.
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
