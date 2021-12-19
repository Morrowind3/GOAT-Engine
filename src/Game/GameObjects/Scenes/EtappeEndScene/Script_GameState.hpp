#ifndef GOAT_ENGINE_SCRIPT_GAMESTATE_HPP
#define GOAT_ENGINE_SCRIPT_GAMESTATE_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include <utility>
#include "../../../../Engine/SceneManager.hpp"
#include "../../Utils/Timer/Object_Timer.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../../Engine/Utilities/EngineCalls.hpp"

using namespace Engine;

class Script_GameState : public Script {
    public:
        Script_GameState(std::shared_ptr<Object_Timer> timer, bool active);
        void onUpdate(double deltaTime) override;
    private:
        std::shared_ptr<Object_Timer> _timer;
        // Utilities
        Globals& _globals = Globals::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Helper methods
        void gameLost();
        void gameWon();
};


#endif //GOAT_ENGINE_SCRIPT_GAMESTATE_HPP
