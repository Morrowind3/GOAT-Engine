#ifndef GOAT_ENGINE_QUITGAMESCRIPT_HPP
#define GOAT_ENGINE_QUITGAMESCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/EngineCalls.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class QuitGameScript : public Script {
    public:
        explicit QuitGameScript(bool active);
        void onExternalEvent();
    private:
        Debug& _debug = Debug::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
};


#endif //GOAT_ENGINE_QUITGAMESCRIPT_HPP
