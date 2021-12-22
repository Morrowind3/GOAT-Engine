#ifndef GOAT_ENGINE_SCRIPT_FLIPGOATS_HPP
#define GOAT_ENGINE_SCRIPT_FLIPGOATS_HPP

#include "../../../../../Engine/Utilities/Input.hpp"
#include "../../../../../Engine/Utilities/Globals.hpp"

using namespace Engine;

class Script_FlipGoats : public Script {
    public:
        Script_FlipGoats(AudioSource& activationSound, bool active);
        void onUpdate(double deltaTime) override;

    private:
        // Utilities
        Input& _input = Input::getInstance();
        Globals& _globals = Globals::getInstance();
        // Variables
        AudioSource& _activationSound;
        bool _activated {false};
};

#endif //GOAT_ENGINE_SCRIPT_FLIPGOATS_HPP
