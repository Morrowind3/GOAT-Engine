#ifndef GOAT_ENGINE_SCRIPT_DEBUGTOGGLE_HPP
#define GOAT_ENGINE_SCRIPT_DEBUGTOGGLE_HPP

#include "../../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../../../Engine/Utilities/Debug.hpp"
#include "../../../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Script_DebugToggle : public Script {
    public:
        explicit Script_DebugToggle(AudioSource& enableSound, AudioSource& disableSound, bool active);
        void onExternalEvent() override;
    private:
        // Utilities
        Debug& _debug = Debug::getInstance();
        // Variables
        AudioSource& _enableSound;
        AudioSource& _disableSound;
};


#endif //GOAT_ENGINE_SCRIPT_DEBUGTOGGLE_HPP
