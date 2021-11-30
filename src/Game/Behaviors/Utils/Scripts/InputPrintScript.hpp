#ifndef GOAT_ENGINE_INPUTPRINTSCRIPT_HPP
#define GOAT_ENGINE_INPUTPRINTSCRIPT_HPP

#include "../../../../Engine/Utilities/Input.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"

using namespace Engine;

class InputPrintScript : public Script {
    public:
        explicit InputPrintScript(bool active);
        void onUpdate(double deltaTime);
    private:
        // Globals
        Input& _input = Input::getInstance();
        Debug& _debug = Debug::getInstance();
        Globals& _globals = Globals::getInstance();
};


#endif //GOAT_ENGINE_INPUTPRINTSCRIPT_HPP
