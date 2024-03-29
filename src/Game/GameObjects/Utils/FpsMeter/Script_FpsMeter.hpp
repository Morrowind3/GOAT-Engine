#ifndef GOAT_ENGINE_SCRIPT_FPSMETER_HPP
#define GOAT_ENGINE_SCRIPT_FPSMETER_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Input.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"
#include "../../../../Engine/Utilities/Clock.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class Script_FpsMeter : public Script {
    public:
        Script_FpsMeter(Text& fpsText, bool active);
        void onStart();
        void onUpdate(double deltaTime);
    private:
        // Globals
        Input& _input = Input::getInstance();
        Debug& _debug = Debug::getInstance();
        Globals& _globals = Globals::getInstance();
        Clock& _clock = Clock::getInstance();
        // Variables
        Text& _text;
};


#endif //GOAT_ENGINE_SCRIPT_FPSMETER_HPP
