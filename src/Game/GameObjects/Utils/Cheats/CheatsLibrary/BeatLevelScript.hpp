#ifndef GOAT_ENGINE_BEATLEVELSCRIPT_HPP
#define GOAT_ENGINE_BEATLEVELSCRIPT_HPP

#include "../../../../../Engine/SceneManager.hpp"
#include "../../../../../Engine/Utilities/Input.hpp"

using namespace Engine;

class BeatLevelScript : public Script {
    public:
        BeatLevelScript(SceneManager& sceneManager, AudioSource& beatGameSfx, bool active);
        // TODO: OnInit when script system supports it properly
        void onUpdate(double deltaTime);
    private:
        // Globals
        Input& _input = Input::getInstance();
        // Variables
        SceneManager& _sceneManager;
        AudioSource& _beatGameSfx;
        unsigned short _activationTimer{0};
        bool _activated{false};
};


#endif //GOAT_ENGINE_BEATLEVELSCRIPT_HPP
