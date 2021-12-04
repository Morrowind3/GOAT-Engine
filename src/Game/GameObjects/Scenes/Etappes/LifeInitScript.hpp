#ifndef GOAT_ENGINE_LIFEINITSCRIPT_HPP
#define GOAT_ENGINE_LIFEINITSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class LifeInitScript : public Script {
    public:
        LifeInitScript(int startHp, bool active);
        void onStart();
    private:
        // Globals
        Globals& _globals = Globals::getInstance();
        // Variables
        int _startHp;
};


#endif //GOAT_ENGINE_LIFEINITSCRIPT_HPP