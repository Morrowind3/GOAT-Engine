#ifndef GOAT_ENGINE_GAMESTATESCRIPT_HPP
#define GOAT_ENGINE_GAMESTATESCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include <utility>
#include "../../../../Engine/SceneManager.hpp"
#include "../../../GameObjects/Meta/Hud/Timer.hpp"

using namespace Engine;

class GameStateScript : public Script {
    public:
        GameStateScript(SceneManager& sceneManager, std::shared_ptr<Timer> timer, bool active) : Script(active), _sceneManager(sceneManager), _timer(std::move(timer)){};
        void onUpdate(double deltaTime) override;
    private:
        std::shared_ptr<Timer> _timer;
        SceneManager& _sceneManager;
        void gameLost();
        void gameWon();
};


#endif //GOAT_ENGINE_GAMESTATESCRIPT_HPP
