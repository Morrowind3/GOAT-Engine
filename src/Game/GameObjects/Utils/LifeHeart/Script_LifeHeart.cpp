#include "Script_LifeHeart.hpp"
#include "../../../Keys.hpp"

Script_LifeHeart::Script_LifeHeart(int filledAtHp, Object_LifeHeart& lifeHeart, bool active):
        Script(active), _lifeHeart{lifeHeart}, _filledAtHp{filledAtHp} {
}

void Script_LifeHeart::onUpdate(double deltaTime) {
    int queryValue = std::stoi(_globals.gameGet(Keys::HP));
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
