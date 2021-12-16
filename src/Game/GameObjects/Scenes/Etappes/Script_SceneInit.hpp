#ifndef GOAT_ENGINE_SCRIPT_SCENEINIT_HPP
#define GOAT_ENGINE_SCRIPT_SCENEINIT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class Script_SceneInit : public Script {
    public:
        Script_SceneInit(unsigned short currentEtappe, unsigned short startHp, bool active);
        void onStart();
    private:
        // Globals
        Globals& _globals = Globals::getInstance();
        // Variables
        unsigned short _currentEtappe, _startHp;
};


#endif //GOAT_ENGINE_SCRIPT_SCENEINIT_HPP
