#ifndef GOAT_ENGINE_GAMESTATESCRIPT_HPP
#define GOAT_ENGINE_GAMESTATESCRIPT_HPP

#include "../../../../Engine/API/GameObjects/GameComponents/Script/Script.hpp"
#include "../../../../Engine/SceneManager.hpp"

using namespace Engine;

class GameStateScript : public Script {
    public:
        GameStateScript(SceneManager& sceneManager, bool active) : Script(active), _sceneManager(sceneManager){};
        void onUpdate(double deltaTime) override;
    private:
        SceneManager& _sceneManager;
        void gameLost();
        void gameWon();
};


#endif //GOAT_ENGINE_GAMESTATESCRIPT_HPP
