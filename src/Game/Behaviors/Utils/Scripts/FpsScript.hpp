#ifndef GOAT_ENGINE_FPSSCRIPT_HPP
#define GOAT_ENGINE_FPSSCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameObject.hpp"
#include "../../../../Engine/Utilities/Input.hpp"
#include "../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class FpsScript : public Script {
    public:
        FpsScript(Text& fpsText, bool active);
        void OnUpdate(double deltaTime);
    private:
        Text& _text;
        Input& _input = Input::GetInstance();
        Debug& _debug = Debug::GetInstance();
};


#endif //GOAT_ENGINE_FPSSCRIPT_HPP
