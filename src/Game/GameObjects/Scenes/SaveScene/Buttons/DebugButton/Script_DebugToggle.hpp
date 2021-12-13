#ifndef GOAT_ENGINE_SCRIPT_DEBUGTOGGLE_HPP
#define GOAT_ENGINE_SCRIPT_DEBUGTOGGLE_HPP

#include "../../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class Script_DebugToggle : public Script {
    public:
        explicit Script_DebugToggle(bool active);
        void onExternalEvent();
    private:
        Debug& _debug = Debug::getInstance();
};


#endif //GOAT_ENGINE_SCRIPT_DEBUGTOGGLE_HPP
