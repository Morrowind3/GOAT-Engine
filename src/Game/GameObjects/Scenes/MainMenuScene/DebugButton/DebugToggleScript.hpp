#ifndef GOAT_ENGINE_DEBUGTOGGLESCRIPT_HPP
#define GOAT_ENGINE_DEBUGTOGGLESCRIPT_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../../Engine/Utilities/Debug.hpp"

using namespace Engine;

class DebugToggleScript : public Script {
    public:
        explicit DebugToggleScript(bool active);
        void onExternalEvent();
    private:
        Debug& _debug = Debug::getInstance();
};


#endif //GOAT_ENGINE_DEBUGTOGGLESCRIPT_HPP
