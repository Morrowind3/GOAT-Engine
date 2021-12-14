#ifndef GOAT_ENGINE_SCRIPT_LIFEINIT_HPP
#define GOAT_ENGINE_SCRIPT_LIFEINIT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class Script_LifeInit : public Script {
    public:
        Script_LifeInit(int startHp, bool active);
        void onStart();
    private:
        // Globals
        Globals& _globals = Globals::getInstance();
        // Variables
        int _startHp;
};


#endif //GOAT_ENGINE_SCRIPT_LIFEINIT_HPP
