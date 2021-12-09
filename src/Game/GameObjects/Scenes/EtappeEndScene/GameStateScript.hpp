#ifndef GOAT_ENGINE_GAMESTATESCRIPT_HPP
#define GOAT_ENGINE_GAMESTATESCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include <utility>
#include "../../../../Engine/SceneManager.hpp"
#include "../../Utils/Timer/Timer.hpp"
#include "../../../../Engine/Utilities/Globals.hpp"
#include "../../../../Engine/Utilities/EngineCalls.hpp"

using namespace Engine;

class GameStateScript : public Script {
    public:
        GameStateScript(std::shared_ptr<Timer> timer, bool active);
        void onUpdate(double deltaTime) override;
    private:
        std::shared_ptr<Timer> _timer;
        // Utilities
        Globals& _globals = Globals::getInstance();
        EngineCalls& _engineCalls = EngineCalls::getInstance();
        // Helper methods
        void gameLost();
        void gameWon();
};


#endif //GOAT_ENGINE_GAMESTATESCRIPT_HPP
