#ifndef GOAT_ENGINE_LIFEHEARTSCRIPT_HPP
#define GOAT_ENGINE_LIFEHEARTSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../GameObjects/Meta/Hud/LifeHeart.hpp"

using namespace Engine;

class LifeHeartScript : public Script {
    public:
        LifeHeartScript(int filledAtHp, LifeHeart& lifeHeart, bool active);
        void onUpdate(double deltaTime);
    private:
        // Globals
        Globals& _globals = Globals::getInstance();
        // Variables
        LifeHeart& _lifeHeart;
        int _filledAtHp, _lastQueryValue = -1;
};


#endif //GOAT_ENGINE_LIFEHEARTSCRIPT_HPP
