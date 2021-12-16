#ifndef GOAT_ENGINE_SCRIPT_ONCLICKSOUND_HPP
#define GOAT_ENGINE_SCRIPT_ONCLICKSOUND_HPP

#include "../../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../../Engine/API/GameObjects/GameComponents/Audio/AudioSource.hpp"

using namespace Engine;

class Script_OnClickSound: public Script {
    public:
        Script_OnClickSound(AudioSource& clickSound, bool active);
        void onExternalEvent() override;
    private:
        AudioSource& _clickSound;
};


#endif //GOAT_ENGINE_SCRIPT_ONCLICKSOUND_HPP
