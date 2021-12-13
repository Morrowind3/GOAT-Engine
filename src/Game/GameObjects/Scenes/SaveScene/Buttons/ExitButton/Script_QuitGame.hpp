#ifndef GOAT_ENGINE_SCRIPT_QUITGAME_HPP
#define GOAT_ENGINE_SCRIPT_QUITGAME_HPP

#include "../../../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../../../Engine/Utilities/EngineCalls.hpp"
#include "../../../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class Script_QuitGame : public Script {
    public:
        explicit Script_QuitGame(bool active);
        void onExternalEvent();
    private:
        Debug& _debug = Debug::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
};


#endif //GOAT_ENGINE_SCRIPT_QUITGAME_HPP
