#ifndef GOAT_ENGINE_FPSSCRIPT_HPP
#define GOAT_ENGINE_FPSSCRIPT_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class FpsScript : public Script {
    public:
        FpsScript(Text& fpsText, bool active);
        void onUpdate(double deltaTime);
    private:
        // Globals
        Input& _input = Input::getInstance();
        Debug& _debug = Debug::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Variables
        Text& _text;
};


#endif //GOAT_ENGINE_FPSSCRIPT_HPP
