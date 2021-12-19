#ifndef GOAT_ENGINE_SCRIPT_LIFEHEART_HPP
#define GOAT_ENGINE_SCRIPT_LIFEHEART_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "Object_LifeHeart.hpp"

using namespace Engine;

class Script_LifeHeart : public Script {
    public:
        Script_LifeHeart(int filledAtHp, Object_LifeHeart& lifeHeart, bool active);
        void onUpdate(double deltaTime);
    private:
        // Globals
        Globals& _globals = Globals::getInstance();
        // Variables
        Object_LifeHeart& _lifeHeart;
        int _filledAtHp, _lastQueryValue = -1;
};


#endif //GOAT_ENGINE_SCRIPT_LIFEHEART_HPP
