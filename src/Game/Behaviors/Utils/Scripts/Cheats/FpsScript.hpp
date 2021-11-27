#ifndef GOAT_ENGINE_FPSSCRIPT_HPP
#define GOAT_ENGINE_FPSSCRIPT_HPP

#include "../../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class FpsScript : public Script {
    public:
        FpsScript(Text& fpsText, bool active);
        void OnUpdate(double deltaTime);
    private:
        // Globals
        Input& _input = Input::GetInstance();
        Debug& _debug = Debug::GetInstance();
        // Variables
        Text& _text;
};


#endif //GOAT_ENGINE_FPSSCRIPT_HPP
